#include <stdio.h>

int d2b()
{   int flag=0;
    int i,a;
    printf("输入一个整型数：\n");
    scanf("%d",&a);
   for(i=31;i>=0;i--)
   if(((a>>i)&1)==1||flag==1)
   {flag=1;
   if(flag)
   printf("%d ",(a>>i)&1);
   } 
  printf("\n");
  printf("\n");
 return 0;
}
