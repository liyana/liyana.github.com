#include <stdio.h>

int main(int argc, const char *argv[])
{
     int i;
     char a[9]="abcdefghi";
     char b[10]={0};
   /*
     for(i=0;i<=8;i+=2){
     b[i]=a[i];
     if(i<8)
     {b[i+1]=a[i+1];}
     }
     */
    
    for(i=0;i<7;i++){
    b[i]=a[i];
    b[i+1]=a[i+1];
    }
    b[i+1]=a[i+1];
    

       printf("%s\n",a);
     printf("%s\n",b);
    return 0;
}
