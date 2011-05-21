#include <stdio.h>
char * strcat(char *dest,const char *src);
int main(int argc, const char *argv[])
{
    char a[10]="abcde";
    char b[20]="hhll";
     printf("%s\n",strcat(b,a));
    return 0;
}
char * strcat(char *dest,const char *src){
int i,j=0;
for(i=0;dest[i];i++)
j++;
for(i=0;src[i];i++)
  {dest[j]=src[i];
   j++;
   }
   dest[j]='\0';
  return dest;

}
