#include <stdio.h>
#include <unistd.h>
typedef struct
{  int hour;
   int min;
   int sec;
}clock_t;

clock_t clock;

int main(int argc, const char *argv[])
{   clock.hour=0;
    clock.min=0;
    clock.sec=0;
     while(1)
     {
       sleep(1);
       update_clock();
       //if(sec/10==0)
      // printf("%d%d:%d%d:%d%d\r",clock.hour,clock.min,clock.sec);
       printf("%d%d:%d%d:%d%d\r",clock.hour,clock.min,clock.sec);
       fflush(stdout);
   }
    return 0;
}
int update_clock(){
    clock.sec++;
    if(clock.sec==60)
      { clock.sec%=60;
        clock.min++;
      }

     if(clock.min==60)
      {  clock.min%=60;
         clock.hour++;
      }

      if(clock.hour==24)
         clock.hour%=24;
            
  }


     










