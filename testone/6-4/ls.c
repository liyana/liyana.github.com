#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#include<pwd.h>
#include<grp.h>

char *getmod(mode_t mode,char *line)   /*Éú³ÉÈšÏÞÃèÊö×Ö·ûŽ®*/
{
        memset(line,0,sizeof(char)*11);

        strcat(line,S_ISDIR(mode)?"d":"-");
        strcat(line,(mode&S_IRWXU)&S_IRUSR?"r":"-");
        strcat(line,(mode&S_IRWXU)&S_IWUSR?"w":"-");
        strcat(line,(mode&S_IRWXU)&S_IXUSR?"x":"-");

        strcat(line,(mode&S_IRWXG)&S_IRGRP?"r":"-");
        strcat(line,(mode&S_IRWXG)&S_IWGRP?"w":"-");
        strcat(line,(mode&S_IRWXG)&S_IXGRP?"x":"-");

        strcat(line,(mode&S_IRWXO)&S_IROTH?"r":"-");
        strcat(line,(mode&S_IRWXO)&S_IWOTH?"w":"-");
        strcat(line,(mode&S_IRWXO)&S_IXOTH?"x":"-");

        return line;
}

int main(int argc, char *argv[]){
 int fd;
  int result;
  int ret=0;
  char mod[11];
  struct stat buf;
  struct passwd *pw;
  struct group *gr;
 
  pw = malloc(sizeof( struct passwd));
  gr = malloc(sizeof( struct group));
  fd = open("1.txt", O_RDWR| O_CREAT, 0600);
  if(fd == -1){
		perror("Open failed");
		ret = -1;
		goto fail;
	}
 
 result=fstat(fd,&buf);
if(result!=0)perror("Problem getting information!");
else 
  pw=getpwuid(buf.st_uid);
  gr=getgrgid(buf.st_gid);
  
  //printf("%s\n",pw->pw_name);
 // printf("%s\n",gr->gr_name);
  //printf("%d\n",buf.st_nlink);
    //printf("%s\n",getmod(buf.st_mode,mod));
  printf("%6s %d %4s %4s %ld %s %s\n",getmod(buf.st_mode,mod),buf.st_nlink,pw->pw_name,gr->gr_name,buf.st_size,ctime(&buf.st_atime),"1.txt");
  close(fd);
fail:
	exit(ret);
return 0;
}
