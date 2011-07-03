/* play process */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define  SEMMSL 250

/* The size of the big array */
/* (currently 256K - nearly 1.5 sec at max rate) */
#define BIGBUFFSIZE 0x040000

/* Types */
typedef struct blockinf_t
{
    int count;	/* How many bytes in this buffer */
    int last;	/* Should we terminate (停止)after this buffer? */
    int setit;	/* Should we re-set the audio parameters(参数) to be the ones here? */
    int speed;
    int bits;
    int stereo;
} blockinf_t;

/* Statics - mostly shared memory etc */
static int shmid, shmid2, *disksemid, *sndsemid;
static char *bigbuff;
static char **buffarr;
static int numbuffs, numsemblks;
static blockinf_t *buffinf;

/* prototypes */
void cleanupsems(void);
static void sighandler(int i);

/* Extern globals */
extern int abuf_size;
extern int audio;

/* extern prototypes */
extern void ErrDie(char *err);
extern void snd_parm(int speed, int bits, int stereo);
extern void sync_audio(void);

void init_shm(void)
{
    int i;

	/* Create, attach and mark for death the big buffer */
    shmid = shmget(IPC_PRIVATE, BIGBUFFSIZE,
	IPC_EXCL | IPC_CREAT | 0600);
    if (shmid == -1)
	ErrDie("shmget");
    bigbuff = shmat(shmid, IPC_RMID, SHM_RND);
    if (bigbuff == (char*)-1)
    {
	perror("shmat");
	if(shmctl(shmid, IPC_RMID, NULL))
		perror("shmctl");
	exit(-1);
    }
    if(shmctl(shmid, IPC_RMID, NULL))
	ErrDie("shmctl");

    /* Create an array of pointers. Point them at equally spaced
    ** chunks in the main buffer, to give lots of smaller buffers
    */
    numbuffs = BIGBUFFSIZE/abuf_size;
    buffarr = (char**)malloc(numbuffs*sizeof(char*));
    for (i=0; i<numbuffs; i++)
	buffarr[i] = bigbuff + i * abuf_size;

    /* Create a small amount of shared memory to hold the info
    ** for each buffer.
    */
    shmid2 = shmget(IPC_PRIVATE, numbuffs*sizeof(blockinf_t),
	IPC_EXCL | IPC_CREAT | 0600);
    if (shmid == -1)
	ErrDie("shmget");
    buffinf = (blockinf_t*)shmat(shmid2, IPC_RMID, SHM_RND);
    if (buffinf == (blockinf_t*)((char*)-1))
    {
	perror("shmat");
	if(shmctl(shmid2, IPC_RMID, NULL))
		perror("shmctl");
	exit(-1);
    }
    if(shmctl(shmid2, IPC_RMID, NULL))
	ErrDie("shmctl");
     
    /* Set up the appropriate number of semaphore blocks */
    numsemblks = numbuffs/SEMMSL;
    if((numsemblks * SEMMSL) < numbuffs)
	numsemblks++;
    /* Malloc arrays of semaphore ids (ints) for the semaphores */
    if ((disksemid = (int*)malloc(sizeof(int)*numsemblks)) == NULL)
	ErrDie("malloc");
    if ((sndsemid = (int*)malloc(sizeof(int)*numsemblks)) == NULL)
	ErrDie("malloc");
    /* Create the semaphores */
    for (i=0;i<numsemblks;i++)
    {
	if ((disksemid[i] = semget(IPC_PRIVATE, SEMMSL,
	    IPC_EXCL | IPC_CREAT | 0600)) == -1)
	    ErrDie("semget");
	if ((sndsemid[i] = semget(IPC_PRIVATE, SEMMSL,
	    IPC_EXCL | IPC_CREAT | 0600)) == -1)
	    ErrDie("semget");
    }
    /* Catch some signals, so we clean up semaphores */
    signal(SIGINT, sighandler);
}


/* Does an up on the appropriate semaphore */
void up(int *semblk, int xsemnum)
{
    struct sembuf sbuf;

    sbuf.sem_num = xsemnum%SEMMSL;
    sbuf.sem_op = 1;
    sbuf.sem_flg = 0;

    if (semop(semblk[xsemnum/SEMMSL], &sbuf, 1) == -1)
	perror("semop");
}

/* Does a down on the appropriate semaphore */
void down(int *semblk, int xsemnum)
{
    struct sembuf sbuf;

    sbuf.sem_num = xsemnum%SEMMSL;
    sbuf.sem_op = -1;
    sbuf.sem_flg = 0;

    if (semop(semblk[xsemnum/SEMMSL], &sbuf, 1) == -1)
	perror("semop");
}

/************************************************************************************
*  disk file read
*************************************************************************************/
void diskread(int infd, int totalplay, char hd_buf[20], int terminate,
              int speed, int bits, int stereo)
{
    int count, i, limited = 0;
    char *tmppt;
    int numread, totalread = 0;
    int first = 1;

    static int triggered = 0;	/* Have we let the writer go? */
    static int cbuff = 0;	/* Which buffer */

    if (totalplay) limited = 1;
    if (totalplay == -1)
    {
	totalplay = 0;
	limited = 1;
    }

    while (1)
    {
	int trgt;

	/* Wait for a clean buffer */
	down(disksemid, cbuff);
	/* Read from the input */
	numread = 0;
	trgt = abuf_size;
	if (limited && (totalread + trgt > totalplay))
	    trgt = totalplay - totalread;
	tmppt = buffarr[cbuff];
	if(first && trgt)
	{
	    buffinf[cbuff].setit = 1;
	    buffinf[cbuff].speed = speed;
	    buffinf[cbuff].bits = bits;
	    buffinf[cbuff].stereo = stereo;
	    if(hd_buf)
	    {
		memcpy(tmppt, hd_buf, 20);
		tmppt += 20; numread = 20;
	    }
	    first = 0; 
	}
	while ( (numread < trgt) &&
	    ((count = read(infd, tmppt, trgt - numread)) != 0) )
	{
	    tmppt += count;
           numread += count;
	}
#ifdef DEBUG
	fprintf(stderr, "in:%d, %d\n", cbuff, numread);
#endif
	/* Update the count for this block */
	buffinf[cbuff].count = numread;
	totalread += numread;
	/* Was it our last block? */
	if (numread < abuf_size)
	    break;
	if(triggered)
	    up(sndsemid, cbuff);
	else
	    if(cbuff == numbuffs-1)
	    {
#ifdef DEBUG
fprintf(stderr, "Triggering (in loop)\n");
#endif
		for(i = 0; i < numbuffs; i++)
		    up(sndsemid,i);
		    triggered = 1;
	    }
	/* Update counter */
	cbuff++;
	cbuff %= numbuffs;
    }
    /* Finish off this set of buffers */
    if(terminate)
    {
	buffinf[cbuff].last = 1;
	if(!triggered)
#ifdef DEBUG
fprintf(stderr, "Triggering (after loop, partial)\n");
#endif
	    /* If it wasn't triggered, we haven't filled past cbuff */
	    for(i = 0; i < cbuff; i++)
		up(sndsemid, i);
	up(sndsemid, cbuff);
    }
    else if((!triggered) && (cbuff == numbuffs-1))
    {
#ifdef DEBUG
fprintf(stderr, "Triggering (after loop, full)\n");
#endif
	for(i = 0; i < numbuffs; i++)
	    up(sndsemid,i);
	    triggered = 1;
    }
    else if(triggered)
	up(sndsemid,cbuff);
    cbuff++;
    cbuff %= numbuffs;
}

/**************************************************************
* write audio data to buffer
***************************************************************/
void audiowrite(void)
{
    int cbuff = 0, count, numwr, trgt;
    char *tmpptr;

    /* Uncatch the signals, so we don't clean up twice */
    signal(SIGINT, SIG_DFL);
     
    /* Child process writes the audio */
    while(1)
    {
	/* Wait for dirty buffer */
	down(sndsemid, cbuff);
	/* Spit to the audio device */
	if(buffinf[cbuff].setit)
	{
	    snd_parm(buffinf[cbuff].speed, buffinf[cbuff].bits,
		buffinf[cbuff].stereo);
	    buffinf[cbuff].setit = 0;
	}
	trgt = buffinf[cbuff].count;
	numwr = 0;
	tmpptr = buffarr[cbuff];
	while ( (numwr < trgt) &&
	    ((count = write(audio, tmpptr, trgt - numwr)) > 0) )
	{
	    if (count == -1)
		ErrDie("write");
	    numwr += count;
	    tmpptr += count;
	}
#ifdef DEBUG
fprintf(stderr, "out:%d, %d\n", cbuff, numwr);
#endif
	/* Was it the last buffer? */
	if (buffinf[cbuff].last)
	{
	    up(disksemid, cbuff);	/* Not really needed */
	    break;
	}
	/* Mark as clean */
	up(disksemid, cbuff);
	/* Update counter */
	cbuff++;
	cbuff %= numbuffs;
    }
    /* Tidy up and be reaped */
    sync_audio();
    close(audio);
    exit(0);
}

/****************************************************************
*  init semaphore
*****************************************************************/
void initsems(int disks, int snds)
{
    int i,j;

    for (i=0;i<numsemblks;i++)
	for (j=0; j<SEMMSL;j++)
	{
	    if(semctl(disksemid[i], j, SETVAL, disks) == -1)
		ErrDie("semctl");
	    if(semctl(sndsemid[i], j, SETVAL, snds) == -1)
		ErrDie("semctl");
	}
}

/****************************************************************
*  cleanup semaphore
*****************************************************************/	
void cleanupsems(void)
{
    int i;

    for (i = 0; i < numsemblks; i++)
    {
	semctl(disksemid[i], 0, IPC_RMID, 0);
	semctl(sndsemid[i], 0, IPC_RMID, 0);
    }
}

/****************************************************************
*  signal semaphore
*****************************************************************/	
static void sighandler(int i)
{
    fprintf(stderr, "signal %d received, cleaning up.\n", i);
    cleanupsems();
    exit(1);
}

