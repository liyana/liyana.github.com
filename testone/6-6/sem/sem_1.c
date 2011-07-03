#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#define MAX 10
#define MAXSTACK 100
        int stack[MAXSTACK][10];
        int size=0;
        sem_t sem;
	pthread_t thread[2];
        pthread_mutex_t mut;
	int number=1,i;
	int fd;
        char buf[1023]={0};
	char str[1024]={0};
       void *thread1()// 一共三个线程（程序启动时，就会有一个默认线程）
{
      while(1){
                pthread_mutex_lock(&mut);//线程互斥
	        if(number>10){ pthread_mutex_unlock(&mut);break;}
		sprintf(str,"%d.dat",number);
                number++;
                pthread_mutex_unlock(&mut);//释放锁
             
                
		 fd=open(str,O_RDONLY);
		read(fd,buf,sizeof(buf));
	
	         printf("Thread1:%s\n",buf);
	
		close(fd);
		
                //sleep(3);  //主动失去控制权    
         }     
printf("thread1 :主函数在等待吗？\n");
pthread_exit(NULL);//自己退出
}

	void *thread2()// 一共三个线程（程序启动时，就会有一个默认线程）
{
       while(1){
                pthread_mutex_lock(&mut);//线程互斥
	        if(number>10){ pthread_mutex_unlock(&mut);break;}
		sprintf(str,"%d.dat",number);
                number++;
                pthread_mutex_unlock(&mut);//释放锁
             
                
		
		
		 fd=open(str,O_RDONLY);
		read(fd,buf,sizeof(buf));
	
	         printf("Thread2:%s\n",buf);

		close(fd);
                //sleep(3);  //主动失去控制权    
         }     
printf("thread1 :主函数在等待吗？\n");
pthread_exit(NULL);//自己退出
}


void thread_create(void)
{
        int temp;
        memset(&thread, 0, sizeof(thread));
          //comment1        /*创建线程*/
        if((temp = pthread_create(&thread[0], NULL, thread1, NULL)) != 0)       //comment2                         //线程号
                printf("线程1创建失败!\n");
        else
                printf("线程1被创建\n");
        if((temp = pthread_create(&thread[1], NULL, thread2, NULL)) != 0)  //comment3
                printf("线程2创建失败");
        else
                printf("线程2被创建\n");
}
     
void thread_wait(void)
{
        /*等待线程结束*/
        if(thread[0] !=0)
 {
                   //comment4
                pthread_join(thread[0],NULL);//等待线程结束，阻塞状态
                printf("线程1已经结束\n");
        }        
if(thread[1] !=0)
 {                //comment5
                pthread_join(thread[1],NULL);
                printf("线程2已经结束\n");
        }
}

int main()//默认线程调用main()
{        
/*用默认属性初始化互斥锁*/
        pthread_mutex_init(&mut,NULL);//用来生成互斥锁 NULL表示使用默认属性
        printf("主函数，正在创建线程\n");
        thread_create();
        printf("主函数，正在等待线程完成任务\n");
        thread_wait();
        return 0;
}
