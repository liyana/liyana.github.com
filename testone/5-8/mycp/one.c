#include <stdio.h>

int one(FILE *src,FILE *dest)
{
char ch;
if(!src||!dest)
printf("fail to open\n");

while((ch=fgetc(src))!=EOF)
  fputc(ch,dest);

 //fclose(src);
 //fclose(dest);
 printf("\n\n");
  return 0;
}
