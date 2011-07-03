/* func_file_f.c */

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main (int argc, char** argv)
{   int ret=0;
    int pFile;
    char buf[] = "hello file";
    char dbuf[128] = {0};

    pFile = open ("1.txt",O_RDWR|O_CREAT,00700);
    if (pFile>=0)
    {  if(write(pFile,buf,strlen(buf))!=strlen(buf)){
		perror("write failed");
		ret = -1;
		goto close_1;
	}
   // write(pFile,buf,strlen(buf));
      // fwrite (buf , 1 , strlen(buf) , pFile );//字符串结束符不应该写到文件中，否则打不开 此处应该将sizeof () 换成 strlen()
        lseek(pFile, 2, SEEK_SET);
        read (pFile, dbuf, sizeof(buf)-5);//读取6个字符
        printf(" read (len %d) string is <%s>\n", sizeof(buf) - 5, dbuf);//llo fi
close_1:      close (pFile);
    }
    return 0;
}
