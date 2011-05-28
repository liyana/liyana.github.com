/* client_tcp.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DEFAULT_PORT 5050

char cbuf[1024] = { 0 };

typedef struct {
   char name[40];
   char director[40];
   char year[20];

}List;
  List li[100];

void get_Movielist(char cbuf[])
{   static int i=0;
 
   
   if(strncmp(cbuf,"Name @: ",8)==0){ strcpy(li[i].name,cbuf+8);}
  
   if(strncmp(cbuf,"Director @: ",12)==0){ strcpy(li[i].director,cbuf+12);}

   if(strncmp(cbuf,"Year @: ",8)==0) {strcpy(li[i].year,cbuf+8);i++;}



}

int listName()
{ int i;
  for(i=0;i<100;i++)
   printf("%s",li[i].name);
  return 0;
}

 int listDirector()
{int j;
for(j=0;j<100;j++)
printf("%s",li[j].director);
return 0;
}

int accordingtoYear()
{
int m;
char a[20]="\n";
char s[10];
printf("Input the year:");
scanf("%s",s);
//strcat(s,a);
//printf("%s\n",a);
  for(m=0;m<100;m++){
//printf("%d\t",strcmp(li[m].year,s));
  if(strncmp(li[m].year,s,4)==0)
  {
   //printf("%s",li[m].year);
   printf("%s",li[m].name);
   printf("%s",li[m].director);
  
 }
}
return 0;
}

int accordingtoDirector()
{ int i;
  //char b[40]="Director @: ";
  char s[20];
  printf("Input the name:");
scanf("%s",s);
//  strcat(b,s);

  for(i=0;i<100;i++)
{/*printf("%s",li[i].director);
printf("%s\b%s\n",li[i].name,b);*/

  if(strncmp(li[i].director,s,strlen(s))==0)
  {
   printf("%s",li[i].name);
   printf("%s",li[i].year);
 }}
return 0;

}

int display()
{int i;
for(i=0;i<100;i++){
  printf("%s",li[i].name);
  printf("%s",li[i].director);
  printf("%s",li[i].year);
}
return 0;
}

int main(int argc, char** argv)
{    FILE * pFile;
    int cPort = DEFAULT_PORT;
    int cClient = 0;
    int cLen = 0;
   int a;
    struct sockaddr_in cli;
    //char cbuf[4096] = {0};
   
    if(argc < 2)
    {
        printf("Uasge: client[server IP address]\n");
        return -1;
    }
   
    memset(cbuf, 0, sizeof(cbuf));
   
    cli.sin_family = AF_INET;     //IPv4 Internet protocols
    cli.sin_port = htons(cPort);
    cli.sin_addr.s_addr = inet_addr(argv[1]);
       pFile = fopen ("2.txt","w");

while(1){

    cClient = socket(AF_INET, SOCK_STREAM, 0);

    if(cClient < 0)
    {
        printf("socket() failure!\n");
        return -1;
    }
   
    if(connect(cClient, (struct sockaddr*)&cli, sizeof(cli)) < 0)//成功返回0
    {
        printf("connect() failure!\n");
        return -1;
    }
   
    cLen = recv(cClient,cbuf, sizeof(cbuf),0); 
  
    if((cLen < 0)||(cLen == 0))
    {
        break;
    }

       fputs (cbuf,pFile );
     
	fgets(cbuf, sizeof(cbuf), pFile);
	get_Movielist(cbuf); 
	
} 

  fclose(pFile);
  close(cClient);
  
while(1){  
     printf("1.listName\n");
     printf("2.listDirector\n");
     printf("3.accordingtoYear\n");
     printf("4.accordingtoDirector\n");
     printf("5.Display all\n");
     printf("Please choose:");
     scanf("%d",&a);

   switch(a)
  { case 1: listName();break;

   case 2:listDirector();break;

   case 3:accordingtoYear();break;

   case 4:accordingtoDirector();break;

   case 5:display();break;
    default:exit(0);
   }
    
}
 
    return 0;
}
