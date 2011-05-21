#include <stdio.h>

int main(int argc, const char *argv[])
{    int flag=0;
    int i,a,j;
    scanf("%d",&a);
   for(i=31;i>=0;i--)
   if((a>>i)&1==1||flag==1)
   {flag=1;
   if(flag)
   printf("%d ",(a>>i)&1);
   }
   /* int n=0;
    int b[32]={0};
    for(i=31;i>=0;i--)
    { if((a>>i)&1)
     b[i]=1;
     else b[i]=0;
     }
     if(b[31]){
     for(i=31;i>=0;i--)
     printf("%d  ",b[i]);}
     else {
     for(i=31;  i>=0;i--)
     {if(b[i]==0)n++;
     if(b[i]) break;}
     for(i=31-n;i>=0;i--)
    printf("%d ",b[i]);}
    return 0;*/
}
