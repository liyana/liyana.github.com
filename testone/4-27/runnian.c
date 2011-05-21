#include <stdio.h>

int main(int argc, const char *argv[])
{
    int year;
    scanf("%d",&year);
    if(year<0)
    printf("输入年份不合法\n");
    else
         if((year%4==0 && year%100!=0)||(year%400==0))
         printf("%d是润年\n",year);
         else
         printf("%d不是润年\n",year);
}
