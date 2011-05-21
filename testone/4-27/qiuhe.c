#include <stdio.h>

int main(int argc, const char *argv[])
{   int i;
     int sum=0;
    for( i=1;i<100;){sum+=i;i+=2;}
    printf("奇数和为%d\n",sum);
    return 0;
}
