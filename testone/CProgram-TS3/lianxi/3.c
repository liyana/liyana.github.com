#include <stdio.h>
#include<stdlib.h>
void Func(char str1[])
{
printf("%d\n",sizeof(str1));
}

int main(int argc, const char *argv[])
{char str[] = "Hello";
char *p = str;
int n = 10;
void *p1 = malloc(100);
char str1[100]={1,2,3};
printf("%d\n",sizeof(str));
printf("%d\n",sizeof(p));
printf("%d\n",sizeof(n));
Func(str1);
//printf("%d\n",sizeof(str1));
printf("%d\n",sizeof(p1));   
    return 0;
}

