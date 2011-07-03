#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
signal(SIGCHLD, sigchld_handler);  //绑定函数 
void sigchld_handler(int sig)   
{   
   pid_t pid;   
   int status;   
   for(; (pid =waitpid(-1, &status, WNOHANG)) >0;)   
   {   
        printf("child %d died:%d\n", pid, WEXITSTATUS(status));// pid, status);   
   }   
//while((pid =waitpid(-1, &status, WNOHANG))>0){}   
   return;   
}  


