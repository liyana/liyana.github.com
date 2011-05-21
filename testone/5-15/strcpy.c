#include <stdio.h>
#include <string.h>
int main(int argc, const char *argv[])
{
    
    char b[15]="helloworldniha";
    char *p1=&b[0];
    char *p2=&b[3];
    printf("%s\n",strcpy(p1,p2));
    printf("%s\n",strcpy(p2,p1));
    return 0;
}
