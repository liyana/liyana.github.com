/* strcpy.c */

#include <stdio.h>
#include <string.h>

int main(int argc, char**argv)
{
    char s[] = "Hello Nanjing";
    char d[] = "Hello Beijing City";
    char m[] = "Hello Shanghai City";
        
    printf("%s\n", d);    //Hello Beijing City
    strcpy(d, s);
    printf("%s\n", d);//Hello Nanjing
    
    printf("%s\n", s);//Hello Nanjing
    strcpy(s, m);              // Here have a bug , do you now why? //s 空间不够大
    printf("%s\n", s);//Hello Shanghai City
        
    return 0;
}
