#include <stdio.h> 
#include <stdlib.h> 
#include <signal.h> 
#include <unistd.h> 
#include <sys/wait.h> 


void handler(int num) 
{ 
	
	int status; 
	int pid = waitpid(-1, &status, WNOHANG); 
	if (WIFEXITED(status)) { 
		printf("The child %d exit with code %d\n", pid, WEXITSTATUS(status)); 
	} 
} 

int main() 
{ 
	
	int c_pid; 
	int pid; 
        int i;
	signal(SIGCHLD, handler); //注册

	if ((pid = fork())) 
	{ 
		 
		c_pid = pid; 
		printf("The child process is %d\n", c_pid); 

		
		for (i = 0; i < 10; i++) 
		{ 
			printf("Do parent things.\n"); 
			sleep(1); 
		} 

		exit(0); 
	} 
	else 
	{ 
		
		printf("I 'm a child.\n"); 
		sleep(2); 
		exit(2); 
	} 
}
