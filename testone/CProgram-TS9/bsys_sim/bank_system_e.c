/* Bank System */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue_queue.c"

/////////////////////////////////////////////////////////////////
SqQueue sq;

#define BSYS_MAX_USER_NUM     1000

/***************************************************************
* Bank System Init
****************************************************************/
int Bank_Sys_Init(void)
{
    return 0;
}

/***************************************************************
* Bank System Quit//停机
****************************************************************/
int Bank_Sys_Term(void)
{
    return 0;    
}

/***************************************************************
* Bank Get One ID
****************************************************************/
int Bank_Sys_Get_Id(void)
{
	  return 0;
}

/***************************************************************
* Bank Call One ID
****************************************************************/
unsigned int Bank_Sys_Call_Id(void)
{
	  return uid;
}

/***************************************************************
* Bank Get All Users Number
****************************************************************/
unsigned int Bank_Get_User_Num(void)
{
	  return num;
}

/***************************************************************
* Bank Get All Users Number
****************************************************************/
int main(int argc, char**argv)
{
    char virtkey = 0;
    
	  Bank_Sys_Init();
	      	
	  for(;;)
	  {
        scanf("%c", &virtkey); 
        
        switch(virtkey)
        {
        	   case 'g'://进队
        	     break;
        	     
        	   case 'c'://出队
        	     break;
        	     
        	   case 'u'://总人数
        	     break;
        	     
        	   case 'e':
	                goto BSYSEXIT;
        	     break;        	     
        	   
        	   default:     	   	   
        	   	   if(virtkey != 10) // "ENTER" Key Code (10)
        	   	   {
        	           printf("Error Enter Key!! \n");
        	       }
        	     break;
        }
	  }
	  
BSYSEXIT:
	  Bank_Sys_Term();
	  
    return 0;
}
