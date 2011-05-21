#include <stdio.h>
#define LETTER 0 
main() 
{ 
    char str[20]="MultiMedia",c; 
    int I; 
    I=0; 
   while((c=str[I])!='\0') {
    I++;
#if LETTER 
    if(c>='a'&&c<='z') 
        c=c-32; 
#else 
    if(c>='A'&&c<='Z') 
        c=c+32; 
#endif 
    printf("%c",c); 
    } 
    printf("\n");
} 
