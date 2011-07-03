/* func_file_s.c */

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char** argv)
{
   int pFile;
    char dbuf[128] = {0}; 
    char sbuf[128] = {0};
    
    pFile = open ("file_f.txt",  O_RDWR |O_CREAT,00700);
    if (pFile >=0)
    {
        printf ("Please Enter String: ");	  
        fgets (dbuf, 128, stdin);
        if(write(pFile,dbuf,strlen(dbuf))!=strlen(dbuf))return -1;
        //printf(" ftell() get is <%d>\n", (int)ftell(pFile));//获取光标所在位置 
        lseek(pFile, 0, SEEK_SET);   //光标指向文件头   
        read (pFile,sbuf, strlen(dbuf));
        printf(" read() string is <%s>\n", sbuf);        
        close (pFile);
    }
    return 0;
}
