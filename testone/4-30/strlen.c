#include <stdio.h>
int strlen (const char * str);
int main(int argc, const char *argv[])
{
    char a[6]="hello";
    int b;
    b=strlen(a);
    printf("%d\n",b);
    return 0;
}

int strlen (const char * str){
int i;
for(i=0;str[i];i++) ;

return i;

}
