#include <stdio.h>

int multi()
{
    int i,x,y,ax,ay,result=0,flag=0;
   start: printf("输入两个整型数：\n");
    if(2!= scanf("%d %d",&x, &y)) goto start;

    if((x>>31)&1)ax=~(x-1);else ax=x;
    if((y>>31)&1)ay=~(y-1);else ay=y;
    if(((x>>31)&1)^((y>>31)&1)) flag=1;
    for(i=0;i<31;i++)
     if((ay>>i)&1)result+=ax<<i;
     if(flag)
     result=~result+1;
     printf("%d * %d =%d",x,y,result);
    return 0;
printf("\n");
printf("\n");
}
