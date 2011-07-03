#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <time.h>
#define PI 3.141592


double add (float  a, float b);
double dec (float a,float b);
double mul (float a,float b);
double div1 (float a,float b);
double sin1 (float a);
double cos1 (float a);
double tan1 (float a);
double abs1 (float a);
double ca_exp (float a);
double ca_log (float a);
double ca_log10 (float a);
double ca_pow (float a,float b);
double ca_rand();


int main(int argc, const char *argv[])
{
    float idata1;
    float idata2;
    int chose;
 
   if(argc==4)
    {
        chose=atoi(argv[1]);
        idata1=atof(argv[2]);
        idata2=atof(argv[3]);
    }
    if(argc==3)
    {
        chose=atof(argv[1]);
        idata1=atof(argv[2]);
    }
    if(argc==2)
    {
        chose=atof(argv[1]);
    }
    if(argc==1)
    {
        printf ("too few arguments !\n");
        exit(1);
    } 
    if(argc>4)
    {
        printf ("too many arguments !\n");
        exit(1);
    }
    switch(chose)
    {
        case 1:
                if (argc!=4)
                {
                    printf("the number of arguments is wrong\n");
                    exit(1);
                }
                printf("%f+%f=%f\n",idata1,idata2,add(idata1,idata2));
                break;
        case 2:
                if (argc!=4)
                {
                    printf("the number of arguments is wrong\n");
                    exit(1);
                }
                printf("%f-%f=%f\n",idata1,idata2,dec(idata1,idata2));
                break;
        case 3:
                if (argc!=4)
                {
                    printf("the number of arguments is wrong\n");
                    exit(1);
                }
                printf("%f*%f=%f\n",idata1,idata2,mul(idata1,idata2));
                break;
        case 4:
                if (argc!=4)
                {
                    printf("the number of arguments is wrong\n");
                    exit(1);}
                if(idata2==0)
                {
                    printf("the argument is wrong!\n");
                    exit(1);
                }
                printf("%f / %f=%f\n",idata1,idata2,div1(idata1,idata2));
                break;
        case 5:
                
                if (argc!=2)
                {
                    printf("the number of arguments is wrong\n");
                    exit(1);
                }
                printf ("PI is:%f\n",PI);
                break;
        case 6:
                if (argc!=3)
                {
                    printf("the number of arguments is wrong\n");
                    exit(1);
                }
        
                printf("sin %f=%f\n",idata1,sin1 (idata1));
                break; 
                
        case 7:
                if (argc!=3)
                {
                    printf("the number of arguments is wrong\n");
                    exit(1);
                }
                printf("cos %f=%f\n",idata1,cos1 (idata1));break; 
        case 8:
                if (argc!=3)
                {
                    printf("the number of arguments is wrong\n");
                    exit(1);
                }
                printf("tan %f=%f\n",idata1,tan1 (idata1));break; 
        case 9:
                if (argc!=3)
                {
                    printf("the number of arguments is wrong\n");
                    exit(1);
                }
                printf("|%f|=%f\n",idata1,abs1(idata1));
                break;
        case 10:
                if (argc!=3)
                {
                    printf("the number of arguments is wrong\n");
                    exit(1);
                }
                printf("%f\n",ca_exp(idata1));
                break;
        case 11:
                if (argc!=3)
                {
                    printf("the number of arguments is wrong\n");
                    exit(1);
                }
             
               if(idata1<0||idata1==0)
               {
                    printf("the argument is wrong!\n");
                    exit(1);
                }
                printf("log %f=%f\n",idata1,ca_log (idata1));
                break;
        case 12:
                if (argc!=3)
                {
                    printf("the number of arguments is wrong\n");
                    exit(1);
                }
              
               if(idata2<0||idata2==0)
                {
                    printf("the argument is wrong!\n");
                    exit(1);
                }
                printf("ln %f=%f\n",idata1,ca_log10(idata1));
                break;
        case 13:
                if (argc!=4)
                {
                    printf("the number of arguments is wrong\n");
                    exit(1);
                }
                printf("%f\n",ca_pow (idata1,idata2));
                break;
        case 14:
                if (argc!=2)
                {
                    printf("the number of arguments is wrong\n");
                    exit(1);
                }
                printf ("%f\n",ca_rand());
                break;
        default:printf("wrong chose!\n");break;
        }

    

         return 0;
}

double  add (float   a,float b)
{
    return a+b;
}

double dec (float  a,float b)
{
    return a-b;
}

double  mul (float a,float b)
{
    return a*b;
}

double div1 (float a,float b)
{
    return (float)a/b;
}

double sin1 (float a)
{
    return sin((double)a);
}

double cos1 (float a)
{
    return cos((long)a);
}

double tan1 (float a)
{
    return tan ((double)a);
}

double abs1 (float a)
{
    return (a>0? a:-a);
}

double ca_exp (float a)
{

  return exp((double)a);  
}

double ca_log (float a)
{
    return log ((double)a);
}

double ca_log10 ( float a)
{
    return log10((double)a);
}

double  ca_pow (float  a,float b)
{
    return pow((double)a,(double)b);
    
}

double ca_rand ()
{
    srand((int)time(0));
    return (double)rand();
}
