#include<string.h>

#include <stdio.h>
char * strcpy (char *dest,const char *scr);



int main(int argc, const char *argv[])
{
    char a[6]="hello";
    char b[18];
    //strcpy(b,a);
    printf("%s\n",strcpy(b,a));
    return 0;
}

char * strcpy (char *dest,const char *scr)
{  int i;
   for (i=0;scr[i];i++)
     dest[i]=scr[i];
     dest[i]='\0';
     return dest;
}
