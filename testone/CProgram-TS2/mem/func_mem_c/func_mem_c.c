/* func_mem_c.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char** argv)
{
    char s[] = "Hello Beijing City";
    char *d;
    
    d = malloc(128);
    
    memcpy(d, s, strlen(s));
    printf("memcpy d string is %s\n", d);//Hello Beijing City
    
   //  memcpy(d, d + 6, strlen(d) - 6);
  //  printf("no.1: memcpy d string is %s\n", d);//Beijing Cityg City

   memmove(d, d + 6, strlen(d) - 6);
   printf("no.1: memmove d string is %s\n", d);//Beijing Cityg City
    
    memmove(d + 7, d, strlen(d));            // Here may have a bug, do you know why?  Nobug 如果d开辟的空间太小的话可能会有bug 
   printf("no.2: memmove d string is %s\n", d);//BeijingBeijing Cityg City
    
    free(d);
    
    return 0;
}
