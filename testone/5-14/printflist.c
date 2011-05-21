#include <stdio.h>
#include <stdarg.h>

void printflist(int begin,...){
    va_list ap;
    char *p;

    va_start(ap,begin);
    p=va_arg(ap,char*);

    while(p){
            fputs(p,stdout);
            putchar('\n');
            p=va_arg(ap,char*);
           }
         va_end(ap);
 
 }


int main(int argc, const char *argv[])
{
    printflist(0,"hello","world","I","am","a","boy",NULL);   
    return 0;
}
