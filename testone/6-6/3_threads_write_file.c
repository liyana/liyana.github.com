#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>

pthread_t thread[3];
pthread_mutex_t mut1,mut2;
pthread_cond_t cond_sum_ready;
pthread_cond_t cond_mut1_ready;
int number=1, serial=1;
char buf1[100] = {0};
char buf2[100] = {0};
char buf3[100] = {0};
char name[30] = {0};
int fd1=0,fd2=0,fd3=0,fd4=0;
sem_t sem;



void *thread1()
{
int k1 = 0;
     
        while(1)
        {                
	
          if(0!=pthread_mutex_trylock(&mut1))
	  {
	      pthread_cond_wait(&cond_mut1_ready, &mut1);
          }
		   if(number >10) {
		 pthread_mutex_unlock(&mut1);
pthread_cond_broadcast(&cond_mut1_ready);
		 break;
		}
		    sprintf(name,"%d.dat",number);
		    k1 = number;	
			
	                number++;
                pthread_mutex_unlock(&mut1);
pthread_cond_broadcast(&cond_mut1_ready);

	sem_wait(&sem); 
	fd1 = open (name,O_RDONLY);
	if(fd1 == -1) {
	printf(" Can't open \n");
	return NULL;
	}
	read(fd1,buf1,100);
	close(fd1);
	sem_post(&sem);
	printf("%s\n",buf1);

loop:	 pthread_mutex_lock(&mut2);
	 printf(" thread1:lock(&mut2) \n");
while(k1 != serial)
{
printf(" thread1:wait(&cond_sum_ready, &mut2) \n");
	pthread_cond_wait(&cond_sum_ready, &mut2);
}

//if(serial != number){		
	//	pthread_mutex_unlock(&mut2);
	//	sleep(3);
	//	goto loop;
	// }
	printf("thread1:ready to open result.dat\n");
	fd4 = open  ("result.dat",O_RDWR | O_CREAT |O_APPEND ,0600);
	if(fd4 == -1) {
	printf(" Can't creat \n");
	return NULL;
	}
printf("thread1:ready to write \n");
	write( fd4,buf1,sizeof(buf1));
	close(fd4);
	serial++;
	pthread_mutex_unlock(&mut2);
	pthread_cond_broadcast(&cond_sum_ready);
	sleep(2);
        }        
printf("thread1 :主函数在等待吗？\n");
pthread_exit(NULL);
}

void *thread2()
{        
int k2 = 0;

            while(1)
        {                
	
           if(0!=pthread_mutex_trylock(&mut1))
{
			pthread_cond_wait(&cond_mut1_ready, &mut1);
}
		   if(number >10) {
		 pthread_mutex_unlock(&mut1);
pthread_cond_broadcast(&cond_mut1_ready);
		 break;
		}
		    sprintf(name,"%d.dat",number);	
			k2 = number; 
	                number++;
                pthread_mutex_unlock(&mut1);
pthread_cond_broadcast(&cond_mut1_ready);

	sem_wait(&sem); 
	fd2 = open (name,O_RDONLY);
	if(fd2 == -1) {
	printf(" Can't open \n");
	return NULL;
	}
	read(fd2,buf2,100);
	close(fd2);
	sem_post(&sem);
	printf("%s\n",buf2);
 
loop1:	 pthread_mutex_lock(&mut2);
printf(" thread2:lock(&mut2) \n");
	while(k2 != serial)
{
printf(" thread2:wait(&cond_sum_ready, &mut2) \n");
		pthread_cond_wait(&cond_sum_ready, &mut2);
}
printf("thread2:ready to open result.dat\n");
	fd4 = open  ("result.dat",O_RDWR | O_CREAT |O_APPEND ,0600);
	if(fd4 == -1) {
	printf(" Can't creat \n");
	return NULL;
	}
printf("thread2:ready to write \n");
	write( fd4,buf2,sizeof(buf2));
	close(fd4);
	serial++;
	pthread_mutex_unlock(&mut2);
	pthread_cond_broadcast(&cond_sum_ready);
        sleep(2);
        } 
printf("thread2 :主函数在等待吗？\n");
pthread_exit(NULL);
}
void *thread3()
{    
int k3 = 0;
            while(1)
        {                
	
            if(0!=pthread_mutex_trylock(&mut1))
{
			pthread_cond_wait(&cond_mut1_ready, &mut1);
}
		   if(number >10) {
		 pthread_mutex_unlock(&mut1);
pthread_cond_broadcast(&cond_mut1_ready);
		 break;
		}
		    sprintf(name,"%d.dat",number);
		    k3 = number;	
			
	                number++;
                pthread_mutex_unlock(&mut1);
pthread_cond_broadcast(&cond_mut1_ready);

	sem_wait(&sem); 
	fd3 = open (name,O_RDONLY);
	if(fd3 == -1) {
	printf(" Can't open \n");
	return NULL;
	}
	read(fd3,buf3,100);
	close(fd3);
	sem_post(&sem);
	printf("%s\n",buf3);

loop2:	pthread_mutex_lock(&mut2);
printf(" thread3:lock(&mut2) \n");
	while(k3 != serial)
{
printf(" thread3:wait(&cond_sum_ready, &mut2) \n");
		pthread_cond_wait(&cond_sum_ready, &mut2);
}

printf("thread3:ready to open result.dat\n");

	fd4 = open  ("result.dat",O_RDWR | O_CREAT |O_APPEND ,0600);
	if(fd4 == -1) {
	printf(" Can't creat \n");
	return NULL;
	}
printf("thread3:ready to write \n");
	write( fd4,buf3,sizeof(buf3));
	close(fd4);
	serial++;
	pthread_mutex_unlock(&mut2);
	pthread_cond_broadcast(&cond_sum_ready);
	
                sleep(2);
        } 
printf("thread3 :主函数在等待吗？\n");
pthread_exit(NULL);
}




void thread_create(void)
{
        int temp;
        memset(&thread, 0, sizeof(thread));
          //comment1        /*创建线程*/
        if((temp = pthread_create(&thread[0], NULL, thread1, NULL)) != 0)       //comment2
                printf("线程1创建失败!\n");
        else
                printf("线程1被创建\n");
        if((temp = pthread_create(&thread[1], NULL, thread2, NULL)) != 0)  //comment3
                printf("线程2创建失败");
        else
                printf("线程2被创建\n");
	if((temp = pthread_create(&thread[2], NULL, thread3, NULL)) != 0)  
               printf("线程3创建失败");
        else
                printf("线程3被创建\n");
	
}

void thread_wait(void)
{
        /*等待线程结束*/
        if(thread[0] !=0)
 {
                   //comment4
                pthread_join(thread[0],NULL);
                printf("线程1已经结束\n");
        }        
	if(thread[1] !=0)
 {                //comment5
                pthread_join(thread[1],NULL);
                printf("线程2已经结束\n");
        }
	if(thread[2] !=0)
{               
                pthread_join(thread[2],NULL);
               printf("线程3已经结束\n");
       }

}

int main()
{        
pthread_cond_t cond_sum_ready=PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_mut1_ready=PTHREAD_COND_INITIALIZER;
/*用默认属性初始化互斥锁*/
	sem_init(&sem,0,2);
        pthread_mutex_init(&mut1,NULL);
	 pthread_mutex_init(&mut2,NULL);
        printf("主函数，正在创建线程\n");
        thread_create();
        printf("主函数，正在等待线程完成任务\n");
       thread_wait();
        return 0;
}

