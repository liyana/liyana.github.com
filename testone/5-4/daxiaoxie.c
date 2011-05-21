#include <stdio.h>
#include <string.h>
int main(int argc, const char *argv[])
{
    char a[]={0};
    scanf("%s",a);
    int i;
    for(i=0;a[i]!='\0';i++)
    { if(a[i]>='A' && a[i]<='Z')
     a[i]|=32;
     else if(a[i]>='a' && a[i]<='z')
     a[i]&=223;
     }
  printf("%s\n",a);
    return 0;
}
