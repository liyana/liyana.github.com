/* strrchr.c */

#include <stdio.h>
#include <string.h>

int main(int argc, char**argv)
{
    char s[] = "mp3.wav.wma";
    char *p;
        
    p = strrchr(s,'.');
    if(p)
    {
      printf("<%s> start <%c> string is %s \n", s, '.', p); //.wma   最后一个点出现在哪
    }
    else
    {
        printf("Not Found!");
    }
    
    return 0;
}
