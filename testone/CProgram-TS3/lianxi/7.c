#include <stdio.h>
#define F(x) x-2
#define D(x)  x*F(x)
int main(int argc, const char *argv[])
{
    printf("%d,%d\n",D(3),D(D(3)));
    return 0;
}
