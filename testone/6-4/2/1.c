#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pwd.h>
#include <time.h>

char *getmod(mode_t mode,char *line)   /*生成权限描述字符串*/
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
char *directory(char *argv)    /*从程序参数取出目录*/
{
   int i;
   for (i=strlen(argv)-1;i;--i)
  if (argv[i]=='/'){
    argv[i+1]='\0';
    break;
  }
   return argv;
}

int main(int argc,char *argv[])
{
  DIR *dirp;
  struct dirent *dirst;
  struct stat finfo;
  char *path,fname[512],mod[11],ctm[10];
  struct passwd *user=NULL;
        struct tm *ltm;


if (argc==1)  path=directory(argv[0]);
else path=argv[1];

      dirp=opendir(path);
        if (!dirp)
        {
    fprintf(stderr,"ERROR\n");
                exit(-1);
        }

        for (dirst=readdir(dirp);dirst;dirst=readdir(dirp))
        {
                strcpy(fname,path);

                lstat(strcat(strcat(fname,"/"),dirst->d_name),&finfo);
                user=getpwuid(finfo.st_uid);

                printf("%s\t%10s\t",getmod(finfo.st_mode,mod),user->pw_name);
                printf("%10d\t%9d\t",finfo.st_ino,finfo.st_size);
                ltm=localtime(&finfo.st_mtime);
                strftime(ctm,9,"%b",ltm);
    printf("%5s",ctm);
                strftime(ctm,9,"%d",ltm);
                printf("%3s",ctm);
                strftime(ctm,9,"%Y",ltm);
                printf("%5s\t",ctm);
                printf("%s\n",dirst->d_name);
        }
        closedir(dirp);
        return 0;
}
