#include <stdio.h>
#include <string.h>
int main(int argc, char **argv) 
{FILE *file1,*file2;
int i;
char c1,c2;
int flag=0;
char str[1024]={0};
file1=fopen("1.txt","r");
file2=fopen("2.txt","w");
while(!feof(file1)){
if(fgets(str, sizeof(str), file1)==NULL)break;
for(i=0;i<sizeof(str);i++){
if(str[i]=='/' && str[i+1]=='/')
{str[i]='\n';str[i+1]='\0';break;}
}
fputs(str,file2);
}


      c1=fgetc(file1);
start:c2=fgetc(file1);

if(c2==EOF){fputc(c1,file2);goto end;}

if(c1=='/' && c2=='*')flag=1;

while(flag){
c1=c2;
c2=fgetc(file1);
if(c1=='*' && c2=='/'){flag=0;c1=fgetc(file1);c2=fgetc(file1);}
else flag=1;
}
if(c1!='/'||c2!='*')
fputc(c1,file2);
c1=c2;
goto start;

end:fclose(file1);
fclose(file2);
return 0;
}
