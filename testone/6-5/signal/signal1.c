#include <signal.h>
#include <sys/types.h>//63个定义
#include <unistd.h>
#include <stdio.h>
/*int main(int argc ,char *argv){
char str[100]={0};
sprintf(str,"kill -s  %s  %s\n","15","3082");
//system(str);
while(1){
system(str);
sleep(20);
}


return 0;
}*/

//int sigqueue(pid_t pid, int sig, const union sigval val);
int main(int argc ,char **argv){
union sigval val;
int sig;
pid_t pid;
 sig=atoi(argv[2]);
 pid=(pid_t)atoi(argv[1]);

while(1){
sigqueue(pid,sig, val);
sleep(3);
}


return 0;
}
