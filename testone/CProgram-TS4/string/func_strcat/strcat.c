/* strcat.c */

#include <stdio.h>
#include <string.h>

int main(int argc, char**argv)
{
    char s[] = "Hello Nanjing";
    char d[] = "Hello Beijing City,";
    
    printf("%s \n", d);        
    strcat(d, s);//d 里没有空间了已经，这样连接可能会出错
    printf("%s \n", d);
    
    return 0;
}
