#include <stdio.h>

int main(int argc, const char *argv[])
{
    int a[20]={1,2,3,4,5,6,7,8,0,9,11,12,13,14,15,16,17,18,19,20};
    int i,j,t;
    for (i=0;i<19;i++)
      for(j=i+1;j<20;j++)
        if(a[i]%2==0 && a[j]%2==1){
         t=a[i];
         a[i]=a[j];
         a[j]=t;
         }
         for(i=0;i<20;i++)
      printf("%d ",a[i]);
      printf("\n");
    return 0;
}
