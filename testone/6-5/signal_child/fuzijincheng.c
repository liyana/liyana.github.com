#include <stdio.h> 
#include <stdlib.h> 
#include <signal.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <sys/types.h> 

/*void handler(int num) 
{ 
	
	int status; 
	int pid = waitpid(-1, &status, WNOHANG); 
	if (WIFEXITED(status)) { 
		printf("The child %d exit with code %d\n", pid, WEXITSTATUS(status)); 
	} 
} */

int main(int argc,char**argv)
{ 
	
        int c_pid; 
	int pid; 
        int i;
	char str[100] = {0};
   

	//signal(SIGCHLD, handler); 

	if ((pid = fork())) //父进程
	{ 
	   execl("/bin/ls", "ls");
			
	} 
	else //子进程
	{ 

		sprintf(str, "%d", getppid());
        	execlp("signal1","signal1",str, argv[1]);
		
	} 
}

