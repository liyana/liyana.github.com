#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i=1000,sum=0;
    sum=i/5;
    sum+=i/25;
    sum+=i/125;
    sum+=i/625;
    printf("1000!里有%d个0\n",sum);
    return 0;
}
