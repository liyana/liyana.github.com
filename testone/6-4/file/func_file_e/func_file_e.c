/* func_file_e.c */

#include <stdio.h>
#include <string.h>

int main (int argc, char** argv)
{
     int pFile;
     unsigned long num = 0;
     pFile = open ("file_f.txt", O_RDONLY);
     if (pFile>=0)
     {
         while (!feof(pFile))
         {
             fgetc (pFile);
             num++;
         }

         close (pFile);
         printf ("Total number of bytes: %d\n", (int)num - 1);//多一个不可见的字符
     }
     return 0;
}
