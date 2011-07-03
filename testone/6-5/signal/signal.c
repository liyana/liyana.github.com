#include <signal.h>
#include <sys/types.h>//63个定义
#include <unistd.h>
#include<stdio.h>
#include <stdlib.h>
void new_op(int,siginfo_t*,void*);
int main(int argc,char**argv)
{
    struct sigaction act;   
    int sig;
    sig=atoi(argv[1]);//初始化
    
    sigemptyset(&act.sa_mask);//置空
    act.sa_flags=SA_SIGINFO;//置有信号 
    act.sa_sigaction=new_op;//绑定函数
    
    if(sigaction(sig,&act,NULL) < 0)//安装
    {
        printf("install sigal error\n");
    }
    
    while(1)
    {
        sleep(2);
        printf("wait for the signal\n");
    }
}
void new_op(int signum,siginfo_t *info,void *myact)
{
    printf("receive signal %d\n", signum);
    sleep(5);
}
