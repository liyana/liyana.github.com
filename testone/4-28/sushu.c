#include <stdio.h>
#include <math.h>
int main(int argc, const char *argv[])
{
    int i,j;
    for(i=2;i<=100;i++)
      { for (j=2;j<=i-1;j++)
          if(i%j==0)break;
          if(j>=i)
          printf("%d ",i);
          }
    printf("\n");
    return 0;
}
