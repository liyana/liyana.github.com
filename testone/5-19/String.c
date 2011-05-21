#include <stdio.h>

int main(int argc, const char *argv[])
{    char a[]="hello";
    char *p="HELLO";
    String1(a);
    String2(p);
    printf("%s\n",(char*)a);
    printf("%s\n",(char*)p);
    //printf("%s\n",a);
    //printf("%s\n",p);
 
    return 0;
}
  String1(char a[]){
   
    return (a);
    }


  String2(char *p){
 
    return(p);
    }
