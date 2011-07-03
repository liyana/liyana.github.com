#include <stdio.h>

int main(int argc, const char *argv[])
{ char  a;int c;
int * b=&c;//指针没有初始化
*b = 100;
a =5;
while(a>=0)
{
a--;
printf("%d\n",a);
}
return 0;
}
