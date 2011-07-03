/* Bank System */  
    
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    
#include "queue_queue.c"
    
/////////////////////////////////////////////////////////////////
SqQueue sq, sqv;


#define TOTAL   1000
#define TOTAL_VIP   1000
/***************************************************************
* Bank System Init
****************************************************************/ 
int Bank_Sys_Init(void) 
{
	QueueCreate(&sq);
	
QueueCreate(&sqv);
	
return 0;

}

/***************************************************************
* Bank System Quit//停机
****************************************************************/ 
int Bank_Sys_Term(void) 
{
	QueueDestroy(&sq);
	
QueueDestroy(&sqv);
	
return 0;

}

/***************************************************************
* Bank Get One ID
****************************************************************/ 
int Bank_Sys_Get_Id(int a) 
{
	
QueueEnterL(&sq, a);
	
return a;

}

int Bank_Sys_GetVIP_Id(int a) 
{
	
QueueEnterL(&sqv, a);
	
return 0;

}

/***************************************************************
* Bank Call One ID
****************************************************************/ 
unsigned int Bank_Sys_Call_Id(void) 
{
    int uid;
	
if (QueueDeleteL(&sq, &uid) != -1)
		
 {		

printf("Bank Call Normal person ID is %d \n", uid);
		
}
	
return 0;

}

unsigned int Bank_Sys_CallVIP_Id(void) 
{
	int uid;
	
if (QueueDeleteL(&sqv, &uid) != -1)
		
 {
printf("Bank Call VIP ID is %d \n", uid);		
}
	
return 0;

}
/***************************************************************
* Bank Get All Users Number
****************************************************************/ 
unsigned int Bank_Get_User_Num(void) 
{
	int num;
	
num = QueueGetTag(&sq);
	
printf(" All Users Number is %d \n", num);
	
return 0;

}

unsigned int Bank_Get_VIP_Num(void) 
{
	int num;
	
num = QueueGetTag(&sqv);
	
printf(" All VIP Number is %d \n", num);
	
return 0;

}

int normal_person() 
{

static int i=0;
char virtkey = 0;
	
while (1)
		
 {
		
scanf("%c", &virtkey);
		
switch (virtkey)
			
 {
		
case 'g':
	 
            if (i < TOTAL)
	   		
             {
		Bank_Sys_Get_Id(i);	//进队
		i++;
              
	     }
			
             break;
		

case 'u':
	Bank_Get_User_Num();	//总人数
	break;
		

case 'e':
	return -1;
		

default:
			
if (virtkey != 10)	// "ENTER" Key Code (10)
			{
				
printf("Error Enter Key!! \n");
			
}
			
break;
			
}
		
}
	
return 0;

}



int VIP() 
{
static int i=0;	
char virtkey = 0;
	
while (1)
		
 {
		
scanf("%c", &virtkey);
		
switch (virtkey)
			
 {
		
case 'g':
				
         if (i < TOTAL_VIP)
		
        {
	 Bank_Sys_GetVIP_Id(i);	//进队
	i++;
	}
	break;
		

case 'u':
	Bank_Get_VIP_Num();	//总人数
	break;
		

case 'e':
	return -1;
		

default:
			
if (virtkey != 10)	// "ENTER" Key Code (10)
{
				
printf("Error Enter Key!! \n");
			
}
			
break;
			
}
		
}
	
return 0;

}


int Clear_record() 
{
	
QueueClear(&sq);
	
QueueClear(&sqv);
	
printf("记录已清空！\n");
	
return 0;

}

int Call_id() 
{
	
if (!QueueEmpty(&sqv, 0))
		
Bank_Sys_CallVIP_Id();
	
	else
	
if (!QueueEmpty(&sq, 0))
		Bank_Sys_Call_Id();
	
	else
		printf("No Waiting People!!\n");
	
return 0;

}

/***************************************************************
* Bank System
****************************************************************/ 

int main(int argc, char **argv) 
{//static int i=0;
//int i=0;	
int c;
	
Bank_Sys_Init();	//创建队
	
while (1) {
		
printf("1.普通客户取号、查看总人数\n");
		
printf("2.VIP客户取号、查看总人数\n");
		
printf("3.叫号\n");
		
printf("4.清空记录\n");
		
printf("5.退出\n");
		
printf("Plese choose:");
		
scanf("%d", &c);
		
switch (c) {
		
case 1:
	normal_person();
	break;
		
case 2:
 	VIP();
	break;
		
case 3:
	Call_id();
	break;
		
case 4:
	Clear_record();
	break;
		
case 5:
	exit(0);
		
default:
	return -1;
		
}
	
}
	
return 0;

}




