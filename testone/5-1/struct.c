#include <stdio.h>
int main(int argc, const char *argv[])
{
 
if(endian())
printf("%s\n","yes");
else
printf("%s\n","no");
//  printf("%d\n",x1.b[i]);
   //z1.ccc.a=2;
//printf("%f\n",z1.ccc.a);
return 0;
}
int endian( ){
  union vv{
    int a;
    char b[4];
}x1;
x1.a=4;
if(x1.b[0]==4)
return 1;
return 0;
}







