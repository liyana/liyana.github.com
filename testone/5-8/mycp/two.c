#include <stdio.h>

int two(FILE *src,FILE *dest)
{
char buffer[1023]={0};
if(!src ||!dest)
printf("fail to open\n");
 else   
   while( fread(buffer,1,1,src)==1)
  
      fwrite(buffer,1,1,dest);

    
    //fclose(src);
   // fclose(dest);
    printf("\n\n");
    return 0;
}
