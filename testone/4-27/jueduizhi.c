#include <stdio.h>

int main(int argc, const char *argv[])
{
    printf("-5 abs is %d\n",myabs(-5));
    return 0;
}
int myabs(int a){
return a>=0?a:-a;}
