/* strchr.c */

#include <stdio.h>
#include <string.h>

int main(int argc, char**argv)
{
    char s[] = "Hello Beijing City";
    char *p,*q;
        
    p = strchr(s,'e');//继续查找 strchr(p+1,'e')
    q=strchr(p+1,'e');
    if(p)
    {
      printf("<%s> start <%c> string is %s   %s\n", s, 'B', p,q);//Beijing City
    }
    else
    {
        printf("Not Found!");
    }
    
    return 0;
}
