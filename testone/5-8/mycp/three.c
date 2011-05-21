#include <stdio.h>

int three(FILE *src,FILE *dest)
{
char str[1023]={0};
if(!src||!dest)
printf("fail to open\n");
 else{ 
 while(fgets(str, sizeof(str), src)!=NULL)
   {    fputs(str,dest);}

  }
  //fclose(src);
 // fclose(dest);
     printf("\n\n");
    return 0;
}
