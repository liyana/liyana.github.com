/* strstr.c */

#include <stdio.h>
#include <string.h>

int main(int argc, char**argv)
{
    char s[]="Hello Beijing Haidian";
    char l[]="Beijing";
    char *p;
    
    p = strstr(s, l);
    if(p)
    {
         printf("%s \n", p);//Beijing Haidian  查找串
    }
    else
    {
      printf("Not Found!!!\n");
    }
    return 0;
}