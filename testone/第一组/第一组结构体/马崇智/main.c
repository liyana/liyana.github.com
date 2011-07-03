#include <stdio.h>
#include <stdlib.h>

typedef struct test{
    char *id;
    char *name;
}test_t,*p_test;

int main(int argc, const char *argv[]){
  
    test_t *p=NULL;

    p = (p_test)malloc(sizeof(test_t));
    p->id = "001";
    p->name = "zhangsan";

    printf("id:\t%s\n",p->id);
    printf("name:\t%s\n",p->name);
    
    free(p);
    return 0;
}
