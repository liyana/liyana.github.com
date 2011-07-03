#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <semaphore.h>
#include <string.h>
#include <stdio.h>
#define MAX 10
#define MAXSTACK 100

	pthread_t thread[5];
        pthread_mutex_t mut,mut1;
	int number=1,i,write_number;
	//int fd,fd1;
	sem_t sem;
        char buf[1023]={0};
	char str[1024]={0};
       void *thread1()// 一共三个线程（程序启动时，就会有一个默认线程）
{	int fd,fd1;  
        int t;
      while(1){
                pthread_mutex_lock(&mut);//线程互斥
	        if(number>10){ pthread_mutex_unlock(&mut);break;}
		
		sprintf(str,"%d.dat",number);
		t=number;
                number++;
                pthread_mutex_unlock(&mut);//释放锁
             
                sem_wait(&sem);
		fd=open(str,O_RDONLY);
		read(fd,buf,sizeof(buf));
		 close(fd);
		sem_post(&sem);

		 pthread_mutex_lock(&mut1);
    loop:        
		 if((t-write_number)!=1){ pthread_mutex_unlock(&mut1);sleep(5);goto loop;}
		 
		 fd1=open("11.dat",O_WRONLY |O_APPEND,0600);
		 
		 write(fd1,buf,strlen(buf));
		 write_number ++;
		 close(fd1);
                 pthread_mutex_unlock(&mut1);
	         printf("Thread1:%s\n",buf);
	
 
                 sleep(3);  //主动失去控制权    
         }     
//printf("thread1 :主函数在等待吗？\n");
pthread_exit(NULL);//自己退出
}

 void *thread2()// 一共三个线程（程序启动时，就会有一个默认线程）
{	int fd,fd1;  
        int t;
      while(1){
                pthread_mutex_lock(&mut);//线程互斥
	        if(number>10){ pthread_mutex_unlock(&mut);break;}
		
		sprintf(str,"%d.dat",number);
		t=number;
                number++;
                pthread_mutex_unlock(&mut);//释放锁
             
                sem_wait(&sem);
		fd=open(str,O_RDONLY);
		read(fd,buf,sizeof(buf));
		 close(fd);
		sem_post(&sem);

		 pthread_mutex_lock(&mut1);

    loop:        if((t-write_number)!=1){ pthread_mutex_unlock(&mut1);sleep(5);goto loop;}
		
		 fd1=open("11.dat",O_WRONLY |O_APPEND,0600);
		 
		 write(fd1,buf,strlen(buf));
		 write_number ++;
		 close(fd1);
                 pthread_mutex_unlock(&mut1);
	         printf("Thread2:%s\n",buf);
	
 
                 sleep(3);  //主动失去控制权    
         }     
//printf("thread1 :主函数在等待吗？\n");
pthread_exit(NULL);//自己退出
}
 void *thread3()// 一共三个线程（程序启动时，就会有一个默认线程）
{	int fd,fd1;  
        int t;
      while(1){
                pthread_mutex_lock(&mut);//线程互斥
	        if(number>10){ pthread_mutex_unlock(&mut);break;}
		
		sprintf(str,"%d.dat",number);
		t=number;
                number++;
                pthread_mutex_unlock(&mut);//释放锁
             
                sem_wait(&sem);
		fd=open(str,O_RDONLY);
		read(fd,buf,sizeof(buf));
		 close(fd);
		sem_post(&sem);
		 pthread_mutex_lock(&mut1);
    loop:        if((t-write_number)!=1){ pthread_mutex_unlock(&mut1);sleep(5);goto loop;}
		
		 fd1=open("11.dat",O_WRONLY |O_APPEND,0600);
		 
		 write(fd1,buf,strlen(buf));
		 write_number ++;
		 close(fd1);
                 pthread_mutex_unlock(&mut1);
	         printf("Thread3:%s\n",buf);
	
 
                 sleep(3);  //主动失去控制权    
         }     
//printf("thread1 :主函数在等待吗？\n");
pthread_exit(NULL);//自己退出
}

  void *thread4()// 一共三个线程（程序启动时，就会有一个默认线程）
{	int fd,fd1;  
        int t;
      while(1){
                pthread_mutex_lock(&mut);//线程互斥
	        if(number>10){ pthread_mutex_unlock(&mut);break;}
		
		sprintf(str,"%d.dat",number);
		t=number;
                number++;
                pthread_mutex_unlock(&mut);//释放锁
             
                sem_wait(&sem);
		fd=open(str,O_RDONLY);
		read(fd,buf,sizeof(buf));
		 close(fd);
		sem_post(&sem);
		pthread_mutex_lock(&mut1);
    loop:        if((t-write_number)!=1){ pthread_mutex_unlock(&mut1);sleep(5);goto loop;}
		 
		 fd1=open("11.dat",O_WRONLY |O_APPEND,0600);
		 
		 write(fd1,buf,strlen(buf));
		 write_number ++;
		 close(fd1);
                 pthread_mutex_unlock(&mut1);
	         printf("Thread4:%s\n",buf);
	
 
                 sleep(3);  //主动失去控制权    
         }     
//printf("thread1 :主函数在等待吗？\n");
pthread_exit(NULL);//自己退出
}

  void *thread5()// 一共三个线程（程序启动时，就会有一个默认线程）
{	int fd,fd1;  
        int t;
      while(1){
                pthread_mutex_lock(&mut);//线程互斥
	        if(number>10){ pthread_mutex_unlock(&mut);break;}
		
		sprintf(str,"%d.dat",number);
		t=number;
                number++;
                pthread_mutex_unlock(&mut);//释放锁
             
                sem_wait(&sem);
		fd=open(str,O_RDONLY);
		read(fd,buf,sizeof(buf));
		 close(fd);
		sem_post(&sem);
		 pthread_mutex_lock(&mut1);
    loop:        if((t-write_number)!=1){pthread_mutex_unlock(&mut1);sleep(5);goto loop;}
		
		 fd1=open("11.dat",O_WRONLY |O_APPEND,0600);
		 
		 write(fd1,buf,strlen(buf));
		 write_number ++;
		 close(fd1);
                 pthread_mutex_unlock(&mut1);
	         printf("Thread5:%s\n",buf);
	
 
                 sleep(3);  //主动失去控制权    
         }     
//printf("thread1 :主函数在等待吗？\n");
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
	if((temp = pthread_create(&thread[2], NULL, thread3, NULL)) != 0)  //comment3
                printf("线程3创建失败");
        else
                printf("线程3被创建\n");
	if((temp = pthread_create(&thread[3], NULL, thread4, NULL)) != 0)  //comment3
                printf("线程4创建失败");
        else
                printf("线程4被创建\n");
	if((temp = pthread_create(&thread[4], NULL, thread5, NULL)) != 0)  //comment3
                printf("线程5创建失败");
        else
                printf("线程5被创建\n");
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
	if(thread[2] !=0)
 {                //comment5
                pthread_join(thread[2],NULL);
                printf("线程3已经结束\n");
        }
	if(thread[3] !=0)
 {                //comment5
                pthread_join(thread[3],NULL);
                printf("线程4已经结束\n");
        }
	if(thread[4] !=0)
 {                //comment5
                pthread_join(thread[4],NULL);
                printf("线程5已经结束\n");
        }
}

int main()//默认线程调用main()
{      
        sem_init(&sem,0,2);
/*用默认属性初始化互斥锁*/
        pthread_mutex_init(&mut,NULL);//用来生成互斥锁 NULL表示使用默认属性
        printf("主函数，正在创建线程\n");
        thread_create();
        printf("主函数，正在等待线程完成任务\n");
        thread_wait();
        return 0;
}
