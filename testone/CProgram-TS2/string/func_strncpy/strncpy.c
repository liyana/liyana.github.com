/* strncpy.c */

#include <stdio.h>
#include <string.h>

int main(int argc, char**argv)
{
    char s[] = "Hello Nanjing";
    char d[] = "Hello Beijing City";
    char m[] = "Hello Shanghai City";
    char *p = strdup(m);//strdup返回一个指针指向m串
    
    strncpy(d, s, strlen(s));
    printf("%s\n", d);//Hello Nanjing City
    
    printf("%s\n", p);//Hello Shanghai City
    strncpy(p, d, strlen(s));  //Hello Nanjingi City
    printf("%s\n", p);
        
    return 0;
}
