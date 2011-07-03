#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
int fd1,fd2;
char buf[1023]={0};
fd1=open("1.txt",O_RDONLY);
fd2=open("2.txt",O_WRONLY |O_CREAT,00700);
while(read(fd1,buf,sizeof(buf)))
{
write(fd2,buf,strlen(buf));
}
close(fd1);
close(fd2);
return 0;

}
