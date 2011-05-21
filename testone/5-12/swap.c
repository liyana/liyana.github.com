#include <stdio.h>
void swap(int *x,int *y){
int temp =*x;
*x=*y;
*y=temp;}



int main(int argc, const char *argv[])
{
    int x=3,y=4;
    printf("x=%d,y=%d\n",x,y);


    swap(&x,&y);
    printf("x=%d,y=%d\n",x,y);
    return 0;
}
