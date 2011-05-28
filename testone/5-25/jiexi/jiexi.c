#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_Movielist(char cbuf[]);
char cbuf[1014] = { 0 };

typedef struct {
   char name[40];
   char director[40];
   char year[20];

}List;
  List li[100];

void get_Movielist(char cbuf[])
{   static int i=0;
 
   
   if(strncmp(cbuf,"Name @:",7)==0){ strcpy(li[i].name,cbuf);}
  
   if(strncmp(cbuf,"Director @:",11)==0){ strcpy(li[i].director,cbuf);}

   if(strncmp(cbuf,"Year @:",7)==0) {strcpy(li[i].year,cbuf);i++;}



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
char a[20]="Year @: ";
char s[10];
printf("Input the year:");
scanf("%s",s);
strcat(a,s);

  for(m=0;m<100;m++){
  if(strncmp(li[m].year,a,12)==0)
  {
   
   printf("%s",li[m].name);
   printf("%s",li[m].director);
  
 }
}
return 0;
}

int accordingtoDirector()
{ int i;
  char b[40]="Director @: ";
  char s[20];
  printf("Input the name:");
scanf("%s",s);
  strcat(b,s);

  for(i=0;i<100;i++)
{
  if(strncmp(li[i].director,b,strlen(b))==0)
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


int main(int argc, const char *argv[])
{ int a;
    FILE *pFile = fopen("movielist.txt", "r");
	while (!feof(pFile)) {
                 cbuf[0]='\0';
		fgets(cbuf, sizeof(cbuf), pFile);
                
		get_Movielist(cbuf); 
	}

      
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

 

