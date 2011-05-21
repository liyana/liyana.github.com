#include <stdio.h>
#include <string.h>
char str[1023]={0};

void jiexi(const char str[]);
void jiexi(const char str[])
{int i;
 int c=0,j=0,k=0,h=0,l=0,m=0,n=0;   
 char str1[1023]={0};//命令数组
 char str2[1023]={0};//参数数组
 char str22[1023]={0};//参数数组
 char str3[1023]={0};//文件名数组
 char str4[1023]={0};//in-file
 char str5[1023]={0};//out-file

    for(i=0;i<1023 &&str[i]!='\n';i++)
    {str1[i]=0;
     str2[i]=0;
     str22[i]=0;
     str3[i]=0;
     str4[i]=0;
     str5[i]=0;
    }

     for(i=0;i<1023 && str[i]!='\n';i++){
    
     if(str[i]==' ') c++; 
     else     break;
      }


     for(i=c;i<1023 && str[i]!='\n';i++){
      if(str[i]==' ')break;
     str1[j]=str[i];
     j++;
     c++;
     }
    
    for(i=c;i<1023 && str[i]!='\n';i++){
    if(str[i]==' ')c++;
    else break;
     }

    if(str[c]!='-')goto l1;

    if(str[c]=='-')
    for(i=c+1;str[i]!='\n' && i<1023;i++){
     if(str[i]==' ')break;
    str2[k]=str[i];
    k++;
    c++;
   }
       
    for(i=c+1;i<1023 && str[i]!='\n';i++){
    if(str[i]==' ') c++;
    else break;
   }goto l3;


l1:if(str[c]!='<')goto l0;
  
   if(str[c]=='<')
   for(i=c+1;i<1023 && str[i]!='\n';i++){
    if(str[i]==' ') c++;
    else break;
   }
     for(i=c+1;str[i]!='\n' && i<1023;i++){
    str4[m]=str[i];
    m++;
    c++;
   }

 for(i=c+1;i<1023 && str[i]!='\n';i++){
    if(str[i]==' ') c++;
    else break;
   }

  if(str[c+1]!='>')goto end;
  if(str[c+1]=='>')goto l5;

l0:    if(str[c]=='>') goto l6;
  if(str[c]!='<'&& str[c]!='>' && str[c]!='-' &&str[c]!='\n')
    for(i=c; str[i]!='\n'&& i<1023;i++){
   if(str[i]==' ')break;
    str3[l]=str[i];
    l++;
    c++;
   } goto l2;

l3: if(str[c+1]!='-')goto l7;
   if(str[c+1]=='-')
     {for(i=c+2;str[i]!='\n' && i<1023;i++){
     if(str[i]==' ')break;
    str22[h]=str[i];
    h++;
    c++;
   }
       
    for(i=c+2;i<1023 && str[i]!='\n';i++){
    if(str[i]==' ') c++;
    else break;
   }
}

  if(str[c+2]=='\n')goto end;


 l7:  if(str[c+1]!='<'&& str[c+1]!='>' && str[c+1]!='-' &&str[c+1]!='\n')
    for(i=c+1;str[i]!='\n'&& i<1023;i++){
    if(str[i]==' ')break;
    str3[l]=str[i];
    l++;
    c++;
   } 

    for(i=c+1;i<1023 && str[i]!='\n';i++){
    if(str[i]==' ') c++;
    else break;
   }

   if(str[c+1]=='>')goto l5;
   if(str[c+1]=='<')
  for(i=c+2;i<1023 && str[i]!='\n';i++){
    if(str[i]==' ') c++;
    else break;
   }
     for(i=c+2;str[i]!='\n' && i<1023;i++){
    if(str[i]==' ')break;
    str4[m]=str[i];
    m++;
    c++;
   }

   for(i=c+2;i<1023 && str[i]!='\n';i++){
    if(str[i]==' ') c++;
    else break;
   }  goto l4;
    
l2:   for(i=c+1;i<1023 && str[i]!='\n';i++){
   if(str[i]==' ') c++;
   else break;
   } 
   if(str[c+1]=='>')goto l5;
   if(str[c+1]=='<')
  for(i=c+2;i<1023 && str[i]!='\n';i++){
    if(str[i]==' ') c++;
    else break;
   }
     for(i=c+2;str[i]!='\n' && i<1023;i++){
    if(str[i]==' ')break;
    str4[m]=str[i];
    m++;
    c++;
   }

 for(i=c+2;i<1023 && str[i]!='\n';i++){
    if(str[i]==' ') c++;
    else break;
   } 
   
     
l4:if(str[c+2]!='>'||str[c+2]=='\n')goto end;
  if(str[c+2]=='>')
   for(i=c+3;i<1023 && str[i]!='\n';i++){
    if(str[i]==' ') c++;
    else break;
    }

  for(i=c+3; str[i]!='\n'&& i<1023;i++){
   if(str[i]==' ')break;
    str5[n]=str[i];
    n++;
    c++;
   }  
   for(i=c+3;i<1023 && str[i]!='\n';i++){
    if(str[i]==' ') c++;
    else break;
    }
if( str[c+3]=='\n')goto end;


l5:   if(str[c+1]=='>')
   for(i=c+2;i<1023 && str[i]!='\n';i++){
    if(str[i]==' ') c++;
    else break;
    }

  for(i=c+2; str[i]!='\n'&& i<1023;i++){
    if(str[i]==' ')break;
    str5[n]=str[i];
    n++;
    c++;
   }

for(i=c+2;i<1023 && str[i]!='\n';i++){
    if(str[i]==' ') c++;
    else break;
    }

 if( str[i]=='\n')goto end;

l6:for(i=c+1;i<1023 && str[i]!='\n';i++){
    if(str[i]==' ') c++;
    else break;
    }

  for(i=c+1; str[i]!='\n'&& i<1023;i++){
    if(str[i]==' ')break;
    str5[n]=str[i];
    n++;
    c++;
   }

for(i=c+1;i<1023 && str[i]!='\n';i++){
    if(str[i]==' ') c++;
    else break;
    }

 if( str[i]=='\n')goto end;

end:
   str1[j]='\0';
   str2[k]='\0';
   str22[h]='\0';
   str3[l]='\0';
   str4[m]='\0';
   str5[n]='\0';


   if(strlen(str1)!=0)printf("命令：%s ",str1);
   if(strlen(str2)!=0)printf("参数：%s ",str2);
    if(strlen(str22)!=0)printf("参数：%s ",str22);
   if(strlen(str3)!=0)printf("文件名：%s ",str3);
   if(strlen(str4)!=0)printf("in-file：%s ",str4);
   if(strlen(str5)!=0)printf("out-file：%s ",str5);


     printf("\n");
}



int main(int argc, const char *argv[])
{
    FILE *file = fopen("1.txt", "r");
	while (!feof(file)) {
               str[0]='\n';
		fgets(str, sizeof(str), file);
		jiexi(str);
   	}

	fclose(file);
    return 0;
}


