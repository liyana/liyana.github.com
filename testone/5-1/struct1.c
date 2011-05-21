#include <stdio.h>

int main(int argc, const char *argv[])
{
    union XX{
     int a;
     char b[4];
  }x1;
  x1.a=0x12345678;
    return 0;
}
