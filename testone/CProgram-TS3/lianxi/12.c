#include <stdio.h>



char *GetMemory0(void)
{
char p[] = "Hello world";

return p;
}

char *GetMemory1(void)
{
const char p[] = "Hello world";

return p;
}

char *GetMemory2(void)
{
char *p = "Hello world";

return p;
}

void Test(void)
{
char*str = NULL;

str = GetMemory0();
printf("%s\n",str);            // 输出结果?

str = GetMemory1();
printf("%s\n",str);            // 输出结果?

str = GetMemory2();
printf("%s\n",str);            // 输出结果?

}

int main(int argc, const char *argv[])
{
    Test();
    return 0;
}
