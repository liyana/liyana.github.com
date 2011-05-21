#include <stdio.h>

union XX{

struct  bit{
  unsigned int one:1;
     unsigned int two:5;
     unsigned int three:2;
     }a;

char b[4];
}z1={};
int main(int argc, const char *argv[])
{  z1.a.one=1;
   z1.a.two=3;
    z1.a.three=1;
    int i;
    for (i=0;i<4;i++)
    printf("%d\n",z1.b[i]);
    return 0;
}
