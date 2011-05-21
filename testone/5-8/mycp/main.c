#include <stdio.h>
#include "one.h"
#include "two.h"
#include "three.h"
#include <stdlib.h>
int main(int argc, const char *argv[])
{   
      int a;

      FILE *src=fopen(argv[1],"r");
      FILE *dest=fopen(argv[2],"w");
      printf("Please select:\n");
      printf("1.cp by char\n");
      printf("2.cp by record\n");
      printf("3.cp by row\n");
      printf("4.exit\n");
      printf("Your choice:");
      scanf("%d",&a);
     switch(a){
        case 1:one(src,dest);break;
        case 2:two(src,dest);break;
        case 3:three(src,dest);break;
        case 4:exit(0);
     }
 
    fclose(src);
    fclose(dest);
   
return 0;
}
