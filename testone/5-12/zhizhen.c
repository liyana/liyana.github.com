#include <stdio.h>

int main(int argc, const char *argv[])
{
    int aa[10]={0};
    int (*a)[10]=&aa;
   // int *b=*a;
   printf("%p\n",a);
   printf("%p\n",(++a));
    return 0;
}
