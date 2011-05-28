/* func_file_f.c */

#include <stdio.h>
#include <string.h>
int main (int argc, char** argv)
{
    FILE * pFile;
    char buf[] = "hello file";
    char dbuf[128] = {0};

    pFile = fopen ("file_f.txt","w+");
    if (pFile!=NULL)
    {
        fwrite (buf , 1 , strlen(buf) , pFile );//字符串结束符不应该写到文件中，否则打不开 此处应该将sizeof () 换成 strlen()
        fseek(pFile, 2, SEEK_SET);
        fread (dbuf, 1, sizeof(buf) - 5, pFile);//读取6个字符
        printf(" fread (len %d) string is <%s>\n", sizeof(buf) - 5, dbuf);//llo fi
        fclose (pFile);
    }
    return 0;
}
