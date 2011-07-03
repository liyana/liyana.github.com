/* calc_a_s.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math.h"
#include <time.h>
#include<assert.h>
#define PI 3.1415962

/* add */
double calc_add( double a1, double a2)
{
     double result = 0;
    
    result = a1 + a2;
    
    return (result);
}

/* sub */
double calc_sub(double s1, double s2)
{
     double result = 0;
    
    result = s1 - s2;
    
    return (result);
}

/* mul */
double calc_mul(double s1, double s2)
{
    double result = 0;

    result =  s1 *  s2;

    return (result );
}    

/* div */
double calc_div(double s1, double s2)
{
    double result = 0;
    
    result = s1 / s2;

    return (result);
}

/* PI */
double calc_PI()
{
    double result = 0;

    result = PI;

    return (result);
}


/* sin */
double calc_sin(double x)
{
    double result = 0;

    result = sin(x);

    return (result);
}    

/* cos */
double calc_cos(double x)
{
    double result = 0;

    result = cos(x);

    return (result);
}    

/* tan */
double calc_tan(double x)
{   
    int i;
    double result = 0;

    for(i=1;i < 100 ; i++)
        assert(x != i*PI/2 );

    result = tan(x);

    return (result);
}    

/* fabs */
double calc_fabs(double x)
{
    double result = 0;

    result = fabs(x);

    return result;
}  

/* exp */
double calc_exp(double x)
{
    double result = 0;

    result = exp(x);

    return result;
}    

/* log */
double calc_log(double x)
{
    double result = 0;
    
    result = log (x);

    return (result);
} 

/* log10 */
double calc_log10(double x)
{
    double result = 0;
    
    result = log10(x);

    return (result);
}  

/* pow */
double calc_pow(double x, double y)
{
    double result = 0;

    result = pow(x,y);

    return (result);
}    

/* rand */
double calc_rand()
{
    double result = 0;
    
    srand((unsigned)time(NULL));
    result =rand ();

    return (result);
}

/* main */
int main (int argc, char** argv)    
{
	  unsigned int calc_mod = 0;
	  double idata  = 0;
      double kdata  = 0;
      double  result = 0;
    
    if(argc < 2)
    {    
    	 printf("enter cmd numbers must > 2!!!\n");
    	 return -1;
    }
    argv ++;
    calc_mod = atoi(*argv);
    
    if (argc > 2)
   { argv ++;    
    idata = atof(*argv);}

    if(argc > 3)
    {argv ++;    
    kdata = atof(*argv);}    
    
    if(argc > 4)
    {printf ("input error\n");return 0;}

    printf("Enter is mod<%d> data_f<%f> data_b<%f> \n", calc_mod, idata, kdata);
    
    switch(calc_mod)
    {
    	    case 1:
    	    	    result = calc_add(idata, kdata);   
                printf("Calc add (%f + %f result is %f\n", idata, kdata, result);  	    	
    	    	break;
    	    	
    	    case 2:
    	    	    result = calc_sub(idata, kdata);
                printf("Calc sub (%f - %f) result is %f\n", idata, kdata, result);     	    	    
    	    	break;

    	    case 3:
                    result = calc_mul(idata, kdata);
                printf("clac mul (%f * %f) result is %f\n",idata, kdata,  result);
                break;

            case 4:
                    if(kdata == 0)
                        {printf ("input error\n");return 0;}

                    result = calc_div(idata, kdata);
                    
                printf ("clac div (%f / %f) result is %f\n",idata, kdata, result );
                break;

            case 5:
                    result = calc_PI();
                printf ("%f\n",result);
                break;

            case 6:
                    result = calc_sin(idata/180*PI);
                    printf("%f\n",result);  
                    break;

            case 7:
                    result = calc_cos(idata/180*PI);
                printf ("%f\n",result);
                break;

            case 8:
                    result = calc_tan(idata/180*PI);
                 printf ("%f\n",result);
                 break;

            case 9:
                    result = calc_fabs(idata);
                printf ("%f\n",result);
                break;

            case 10:
                    result = calc_exp(idata);
                printf("%f\n",result);
                break;
                

            case 11:
                    if(idata <= 0)
                        { printf ("input error\n"); return 0;}

                    result = calc_log(idata);
                printf("%f\n",result);
                break;

            case 12:
                    if(idata <= 0)
                        {printf("input error\n");  return 0;}

                    result = calc_log10(idata);
                printf("%f\n",result);
                break;

             case 13:
                    result = calc_pow(idata,kdata);
                 printf("%f\n",result);
                 break;

             case 14:
                    result = calc_rand();
                 printf ("%f\n",result);
                 break;


    	    default:
    	    	    printf("Enter calc mod error!!!\n");
    	    	break;
    }
    
    return 0;
}
