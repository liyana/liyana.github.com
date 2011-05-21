#include <stdio.h>

char * strchr(const char *str,char ch);
char * strchr(const char *str,char ch){
  /*
  int * p=str;
  if(*p!=ch)
  p++;
printf("%d\n",*p);
*/

  int i;
  char *p = str;

  for(i=0;*(p + i);i++)
    if(*(p+i) == ch)return (p+i);

    return NULL;

 /* int i;
  for(i=0;str[i];i++)
  if(str[i]==ch)
  return &str[i];

  return NULL;*/
}
int main(int argc, const char *argv[])
{   int i;
 
 char str[20]="hello";
 char *p=str;
    char ch='e';
   // strchr(str,ch);
    printf("%d\n",(strchr(str,ch)-p));
    return 0;
}
