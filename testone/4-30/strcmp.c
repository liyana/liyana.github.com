#include <stdio.h>
int scrcmp (const char *s1,const char *s2);
int main(int argc, const char *argv[])
{
    char a[6]="hello";
    char b[6]="hello";
    if(strcmp(a,b)==0)
    printf("a=b");
     else
       if(strcmp(a,b)==-1)
        printf("a<b");
    else
    printf("a>b");
    return 0;
}

int scrcmp (const char *s1,const char *s2)
{
  int i;
  for(i=0;s1[i]==s2[i];i++)
    if(s1[i]=='\0')

    return 0;

    if(s1[i]>s2[i])
   return 1;

   if(s1[i]<s2[i])
   return -1;




}
