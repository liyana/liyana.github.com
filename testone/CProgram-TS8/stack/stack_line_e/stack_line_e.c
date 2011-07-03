/* stack */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack_stack.c"

void LineEdit()
{
    SqStack S;
    SqStack T;
    char str[1024];
    int strlens = 0;
    char e;
    char ch;
    
    StackCreate(&S);
    StackCreate(&T);    
    
    ch = getchar();
    
    while(ch != EOF)
    {
        while((ch != EOF)&& (ch!='\n'))
        {
            switch(ch)
            {
                case '#':   // Back One
                    StackPop(&S, &ch); //弹出的内容赋给ch
                  break;
                  
                case '@':   // Clear All
                	  StackClear(&S);
                	break;
                	
                default: 
                	  StackPush(&S, ch); //ch入栈
                	break; 
             }
             
             ch = getchar();
         }
         
         if(ch == '\n')
         {
             StackPush(&S, ch);
         }
         
         while(!StackEmpty(&S)) //s栈不空
         { 
             StackPop(&S, &e);
             StackPush(&T, e);
         }
         
         while(!StackEmpty(&T)) //T栈不空
         { 
             StackPop(&T, &e);
             str[strlens++] = e;
         }
         
         if(ch != EOF)
         {
             ch = getchar();
         }
    }
    
    str[strlens] = '\0';
    
    printf("\n%s\n",str);
    printf("%d\n",strlen(str));
    
    StackDestroy(&S);
    StackDestroy(&T);
}

int main(int argc, char**argv)
{
	  LineEdit();
    
    return 0;	
}
