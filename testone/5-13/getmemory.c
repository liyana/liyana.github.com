#include <stdio.h>
void *GetMemory(int size){
   char Memory[1024];
   return Memory;
   }
int main(int argc, const char *argv[])
{
   printf("%p\n", GetMemory(100));
    return 0;
}
