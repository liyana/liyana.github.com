#include <stdio.h>
#include <string.h>
int exchange()
{
    char a[]={0};
    printf(" 输入要转换的字符串：\n");
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
printf("\n");
printf("\n");
}
