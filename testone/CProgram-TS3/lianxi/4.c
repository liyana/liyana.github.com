#include <stdio.h>
void foo(void)
{
unsigned int a = 6;
int b = -20;
unsigned c = 0;

((a+b) > 6) ? puts("> 6") : puts("<= 6");

c = a + b ;
printf("c=%d\n", c);
}

int main(int argc, const char *argv[])
{
    foo();
    return 0;
}
