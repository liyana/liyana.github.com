#include <stdio.h>
void say_hello(const char *str)
{  printf("Hello %s\n",str);

}

 typedef void f_tt(const char *);
      f_tt *f1=say_hello;


int main(int argc, const char *argv[])
{
    /* typedef void(*f_t)(const char *);
     f_t f=say_hello;
     f("world");*/

    /* typedef void f_tt(const char *);
     f_tt *f1=say_hello;*/
     f1("nihao");
    return 0;
}
