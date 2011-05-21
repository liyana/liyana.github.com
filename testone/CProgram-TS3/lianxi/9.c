#include <stdio.h>

int main(int argc, const char *argv[])
{
    char *p=NULL;
    short nMemSize=0;
    p=(char *)malloc(1024);
    nMemSize=sizeof(p);
    printf("%d\n",nMemSize);
    return 0;
}
