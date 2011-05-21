#include <stdio.h>

int encryption()
{
    char a[]={0};
    printf("输入需要加密的：\n");
    scanf("%s",a);
    int i, c=9;
    for(i=0;a[i]!='\0';i++)
    a[i]^=c;
    printf("加密后：%s\n",a);
    for(i=0;a[i]!='\0';i++)
    a[i]^=c;
    printf("解密后：%s\n",a);
printf("\n");
printf("\n");
    return 0;
}
