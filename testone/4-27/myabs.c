#include <stdio.h>

int main(int argc, const char *argv[])
{
    printf("%d\n",myabs(-5));
    return 0;
}
int myabs(int a)
{
if(a>=0)return a;
else return -a;}
