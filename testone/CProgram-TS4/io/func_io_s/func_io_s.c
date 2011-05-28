/* function */

#include <stdio.h>

int main( int argc, char ** argv)
{
    char ch = 0;                // Here have a bug, Do you know why? 编码从0开始  初始化时赋一个与结果不相干扰的值  比如 -1

    if((ch = getchar())  !=  EOF)
    {
        putchar(ch);
        putchar('\n');
    }

    return 0;
}
