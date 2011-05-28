/* func_mem_r.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char** argv)
{
     char *p;

     p = (char *)malloc(8);
     if(p == NULL)
     {
         printf("malloc failure!\n");
         return -1;
     }
     
     memset(p, 0x61, 9);                 // Here have a bug, do you know why? 只开辟了8个空间  添了9个a  第10个位置是'\0'
     p = (char *)realloc(p, 8912);
     memset(p + 6, 0x62, 8);//  改为p+10 只输出9个a 此时遇到'\0', 结束
     printf("mem contents is %s \n", p);
    printf("%c\n",*(p+14));
     
     free(p);
     
     return 0;
}
