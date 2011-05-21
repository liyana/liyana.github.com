#include <stdio.h>

int main(int argc, const char *argv[])
{
    const char a='m';
    char b=a;
//    a='n' ; //a can't be changed
    printf("%c %c\n",a,b);
    return 0;
}
