#include <stdio.h>
void say_hello(const char *str)
{
    printf("Hello %s\n",str);
    }


int main(int argc, const char *argv[])
{
    void (*f)(const char *)=say_hello;
    f("Mike");
    return 0;
}
