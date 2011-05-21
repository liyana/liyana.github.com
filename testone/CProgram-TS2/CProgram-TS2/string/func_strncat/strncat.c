/* strncat.c */

#include <stdio.h>
#include <string.h>

int main(int argc, char**argv)
{
    char s[] = "Hello Nanjing";
    char d[] = "Hello Beijing City,";
    
    printf("%s \n", d);//Hello Beijing City,        
    strncat(d, s, sizeof(s) - 8);//14-8 //Hello Beijing City,Hello 
    printf("%s \n", d);
    
    return 0;
}
