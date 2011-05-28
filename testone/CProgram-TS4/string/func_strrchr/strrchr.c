/* strrchr.c */

#include <stdio.h>
#include <string.h>

int main(int argc, char**argv)
{
    char s[] = "mp3.wav.wma";
    char *p;
        
    p = strrchr(s,'.');//该字符最后一次出现的位置
    if(p)
    {
      printf("<%s> start <%c> string is %s \n", s, '.', p);
    }
    else
    {
        printf("Not Found!");
    }
    
    return 0;
}
