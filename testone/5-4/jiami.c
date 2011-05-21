#include <stdio.h>

int main(int argc, const char *argv[])
{
    char a[]={0};
    scanf("%s",a);
    int i, c=9;
    for(i=0;a[i]!='\0';i++)
    a[i]^=c;
    printf("加密后：%s\n",a);
    for(i=0;a[i]!='\0';i++)
    a[i]^=c;
    printf("解密后：%s\n",a);

    return 0;
}
