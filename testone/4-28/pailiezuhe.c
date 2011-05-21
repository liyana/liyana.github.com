#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i,j,k,m,count=0;
    for(i=1;i<=4;i++)
     { for(j=1;j<=4;j++)
       { for(k=1;k<=4;k++)
         {  if(i!=j&&i!=k&&j!=k)
           {count++;
           m=i*100+j*10+k;
           printf("%d ",m);
           }
          }
        }
     }
     printf("\n");
     printf("The count is %d\n",count);
return 0;
}
