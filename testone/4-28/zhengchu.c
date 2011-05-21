#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i,j=0;
    for(i=1;i<=200;i++)
     { if (i%3==0)continue;
    printf("%6d",i);
    j++;
    if(j%8==0) printf("\n");
    } 
    printf("\n");     
}
