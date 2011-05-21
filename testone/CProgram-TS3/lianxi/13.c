#include <stdio.h>
int fn(int a, int b)
{if(b>0)
{
    return a*fn(a, b-1);
}
else
{
    return 1;
}
}

void main()
{
    printf("fn(5, 3) value is %d\n", fn(5, 3));       // 输出结果? 125
}
