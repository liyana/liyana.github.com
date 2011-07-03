/* wavplay.c -- By fqheda */

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/soundcard.h>

#include "wavfmt.h"

/* Types and constants */
typedef enum sndf_t {
   F_UNKNOWN, 
   F_WAV
} sndf_t;

#define MSPEED	1
#define MBITS	2
#define MSTEREO	4

/* Globals */
int forked;
int audio;
int abuf_size;
int fmt_mask;

extern void init_shm(void);
extern void diskread(int outfd, int bcount, char hd_buf[20], int terminate,int speed, int bits, int stereo);
extern volatile void audiowrite(void);
extern void initsems(int disks, int snds);
extern void cleanupsems(void);

void playwav(int thefd, char hd_buf[20], int mods, int speed, int bits, int stereo);

////////////////////////////////////////////////////////////////////////////////
void ErrDie(char * err)
{
	  fprintf(stderr, "wavplay: %s: %s\n",err, strerror(errno));
	  exit(-1);
}

void Die(char * err)
{
	  fprintf(stderr, "wavplay: %s\n", err);
	  exit(-1);
}

//////////////////////////////////////////////////////////////////////////////
#define AUDIO_DEV "/dev/dsp"

/**********************************************************
*  open audio driver and get audio params
***********************************************************/
void init_sound(void)
{
    /* Attempt to open the audio device */
    audio = open(AUDIO_DEV, O_RDWR);
    if (audio == -1)
    {
        ErrDie(AUDIO_DEV);
    }
	  
    abuf_size = 65536;
    
    if (ioctl(audio, SNDCTL_DSP_GETFMTS, &fmt_mask) < 0)
    {
        ErrDie(AUDIO_DEV);
    }
}

/**********************************************************
*  sync audio for params config
***********************************************************/
void sync_audio(void)
{
    if (ioctl (audio, SNDCTL_DSP_SYNC, NULL) < 0)
    {
	      ErrDie(AUDIO_DEV);
	  }
}

/**********************************************************
*  config audio params
***********************************************************/
void snd_parm(int speed, int bits, int stereo)
{
    static int oldspeed = -1, oldbits = -1, oldstereo = -1;

    if ((speed != oldspeed) || (bits != oldbits) || (stereo != oldstereo))
    {
	      sync_audio();

	      if (ioctl(audio, SNDCTL_DSP_SAMPLESIZE, &bits) < 0)
	      {
	          ErrDie(AUDIO_DEV);
	      }
	      
	      if (ioctl(audio, SNDCTL_DSP_STEREO, &stereo) < 0)
	      {
	          ErrDie(AUDIO_DEV);
	      }
	      
	      if (ioctl(audio, SNDCTL_DSP_SPEED, &speed) < 0)
	      {
	          ErrDie(AUDIO_DEV);
        }
        
     }
     oldspeed = speed;
     oldbits = bits; 
     oldstereo = stereo;
}

////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
	  int thefd;			/* The file descriptor */
	  int speed, bits, stereo;	/* Audio parameters */
	  int timelim;			/* Recording time in secs */
	  int samplim;			/* Recording time in samples */
	  int timejmp;			/* Skip time in secs */
	  int sampjmp;			/* Skip time in samples */
	  int bcount;			/* Number of bytes to record */
	  int bjump;			/* Number of bytes to skip */
	  sndf_t filetype;		/* The file type */
	  int mods;			/* So user can override */
         int count;
	  pid_t pid;
	  char hd_buf[20];
	  
	  /* Default Params */
	  speed = 8000;
	  bits = 8;
	  stereo = 0;
	  timelim = 0;
	  samplim = 0;
	  bcount = 0;
	  timejmp = 0;
	  sampjmp = 0;
	  bjump = 0;
	  filetype = F_WAV;
	  mods = 0;
	  
	  if ((thefd = open(argv[optind], O_RDONLY)) == -1)
	  {
		    ErrDie(argv[optind]);
		}

	  /* Open and set up the audio device */
	  init_sound();

	  /* Set up the shared buffers and semaphore blocks */
	  init_shm();
	  
		count = read(thefd, hd_buf, 20);
		if (count < 0)
		{
			  ErrDie("read");
		}
		
		if (count < 20)
		{
		    printf("input file less than 20 bytes long.");
		}
    
		initsems(1, 0);

		pid = fork();
		if(!pid)
		{
		    audiowrite();	/* Doesn't return */
		}
		forked = 1;
    
    if(strstr(hd_buf, "RIFF") != NULL)
    {
			   playwav(thefd, hd_buf, mods, speed, bits, stereo);
		}
		else
		{
			   printf("Play file is not wav format!!!\n");
		}
		
		wait(NULL);
		cleanupsems();

     return 0;
}

/***********************************************************************
*  play wav file
************************************************************************/
void playwav(int thefd, char hd_buf[20], int mods, int speed, int bits, int stereo)
{
    wavhead wavhd;
    int count;

    memcpy((void*)&wavhd, (void*)hd_buf, 20);
    count = read(thefd, ((char*)&wavhd)+20, sizeof(wavhd) - 20);
    
    if(wavhd.format != 1)
    {
        printf("input is not a PCM WAV file");
    }
    
    if (! (mods&MSPEED))
    {
	      speed = wavhd.sample_fq;
	  }
	  
    if (! (mods&MBITS))
    {
	      bits = wavhd.bit_p_spl;
	  }
	  
    if (! (mods&MSTEREO))
    {
    	  stereo = wavhd.modus - 1;
    }
    
    printf("Playing WAVE : %d bit, Speed %d %s ...\n", bits, speed, (stereo)? "Stereo" : "Mono");
    
    diskread(thefd, 0, NULL, 1, speed, bits, stereo);
}
