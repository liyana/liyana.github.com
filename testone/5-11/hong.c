#include <stdio.h>
//#define PRINT_INT(x)  printf(#x "=%d\n",x);
int main(int argc, const char *argv[])
{
   // MAX(3,4)
  // printf("helloworld\n");
  //  PRINT_INT(3+5);
   
   printf("%d\n",__LINE__);
   printf("%s\n",__FILE__);
   printf("%s\n",__DATE__);
   printf("%s\n",__TIME__);
   printf("%d\n",__STDC__);
//   printf("%s\n",__fun__);
   return 0;
}
