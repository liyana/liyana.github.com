/* calc_a_s.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <time.h>
#define PI 3.141592

/* add */
double  calc_add( double a1,double a2)
{
    
    return a1+a2;
}

/* sub */ 
double calc_sub(double a1,double a2)
{
    
    return a1-a2;
}

//mutli
double calc_multi(double a1,double a2)
{
	double result = 0;

	result = a1 * a2;

	return result;
}

//div
double calc_div(double a1,double a2)
{   

	double result = 0;
	
	result = a1 / a2;
	
	return result;
}

//PI
double calc_PI()
{
    double result = 0;

    result = PI;

    return result;
}
//sin
double calc_sin(double a)
{
    double result = 0;

    result = sin(a);
    
    return result;
}

//cos
double calc_cos(double a)
{
    double result = 0;

    result = cos(a);

    return result;
}

//tan
double calc_tan(double a)
{
    double result = 0;

    result = tan(a);

    return result;
}

//fabs
double calc_fabs(double a)
{
    double result = 0;

    result = fabs(a);

    return result;
}

//exp
double calc_exp(double a)
{   
    double result = 0;

    result = exp(a);

    return result;
}

//log
double calc_log(double a)
{   
    assert(a>0);

    double result = 0;

    result = log(a);

    return result;
}

//log10
double calc_log10(double a)
{
    assert(a>0);

    double result = 0;

    result = log10(a);

    return result;
}

//pow
double calc_pow(double a,double b)
{
    double result = 0;

    result = pow(a,b);

    return result;
}

//rand
double calc_rand()
{
    double result = 0;

    srand((int)time(0));
    result = rand();

    return result;
}

/* main */
int main (int argc, char** argv)   
{
    unsigned int calc_mod = 0;
    double idata  = 0;
    double kdata  = 0;
    double result = 0;
    
    if(argc < 2 || argc > 4)
    {
        printf("enter cmd numbers must greater than 2 and less than 5!!!\n\n");
	    printf("命令格式如下所示：\n");
    	printf("./calc_sim 1 xxx xxx      add\n");
    	printf("./calc_sim 2 xxx xxx      sub\n");
    	printf("./calc_sim 3 xxx xxx      multi\n");
    	printf("./calc_sim 4 xxx xxx      div\n");
    	printf("./calc_sim 5              PI\n");
    	printf("./calc_sim 6 xxx          sin\n");
    	printf("./calc_sim 7 xxx          cos\n");
    	printf("./calc_sim 8 xxx          tan\n");
    	printf("./calc_sim 9 xxx          fabs\n");
    	printf("./calc_sim 10 xxx         exp\n");
    	printf("./calc_sim 11 xxx         log\n");
    	printf("./calc_sim 12 xxx         log10\n");
   	    printf("./calc_sim 13 xxx xxx     pow\n");
    	printf("./calc_sim 14             rand\n");

    	return -1;
    }

    argv++;
    calc_mod=atoi(*argv);

    if(calc_mod < 1 || calc_mod > 14){
	     printf("命令格式如下所示：\n");
    	     printf("./calc_sim 1 xxx xxx      add\n");
    	     printf("./calc_sim 2 xxx xxx      sub\n");
    	     printf("./calc_sim 3 xxx xxx      multi\n");
    	     printf("./calc_sim 4 xxx xxx      div\n");
    	     printf("./calc_sim 5              PI\n");
    	     printf("./calc_sim 6 xxx          sin\n");
    	     printf("./calc_sim 7 xxx          cos\n");
    	     printf("./calc_sim 8 xxx          tan\n");
    	     printf("./calc_sim 9 xxx          fabs\n");
    	     printf("./calc_sim 10 xxx         exp\n");
    	     printf("./calc_sim 11 xxx         log\n");
    	     printf("./calc_sim 12 xxx         log10\n");
   	     printf("./calc_sim 13 xxx xxx     pow\n");
    	     printf("./calc_sim 14             rand\n");
	return -1;
	
        }

    
    if(argc==2){
	
	    printf("Enter is mod<%d>  \n", calc_mod);
    
        switch(calc_mod){
            case 5:
                result = calc_PI();
                printf("calc PI result is %f\n",result);
                break;
	        case 14:
                result = calc_rand();
                printf("calc rand result is %f\n",result);
                break;
            default:
                if(calc_mod==1)
                    printf("add 格式：./calc_sim 1 xxx xxx\n");
                if(calc_mod==2)
                    printf("sub 格式：./calc_sim 2 xxx xxx\n");
                if(calc_mod==3)
                    printf("multi 格式:./calc_sim 3 xxx xxx\n");
                if(calc_mod==4)
                    printf("div 格式:./calc_sim 4 xxx xxx\n");
                if(calc_mod==5)
                    printf("PI 格式:./calc_sim 5\n");
                if(calc_mod==6)
                    printf("sin 格式:./calc_sim 6 xxx\n");
                if(calc_mod==7)
                    printf("cos 格式:./calc_sim 7 xxx\n");
                if(calc_mod==8)
                    printf("tan 格式:./calc_sim 8 xxx\n");
                if(calc_mod==9)
                    printf("fabs 格式:./calc_sim 9 xxx\n");
                if(calc_mod==10)
                    printf("exp 格式:./calc_sim 10 xxx\n");
                if(calc_mod==11)
                    printf("log 格式:./calc_sim 11 xxx\n");
                if(calc_mod==12)
                    printf("log10 格式:./calc_sim 12 xxx\n");
                if(calc_mod==13)
                    printf("pow 格式:./calc_sim 13 xxx xxx\n");
                if(calc_mod==14)
                    printf("rand 格式:./calc_sim 14\n");
                
                break;
	
        }   
    }

    if(argc==3){

        argv ++;
        idata = atof(*argv);

	    printf("Enter is mod<%d> data_f<%f> \n", calc_mod, idata);

	    switch(calc_mod){
	        case 6:
                result = calc_sin(idata);
                printf("calc sin (%f) result is %f\n",idata,result);
                break;

            case 7:
                result = calc_cos(idata);
                printf("calc cos (%f) result is %f\n",idata,result);
                break;

            case 8:
                result = calc_tan(idata);
                printf("calc tan (%f) result is %f\n",idata,result);
                break;

            case 9:
                result = calc_fabs(idata);
                printf("calc fabs (%f) result is %f\n",idata,result);
                break;

            case 10:
                result = calc_exp(idata);
                printf("calc exp (%f) result is %f\n",idata,result);
                break;

            case 11:
                if(idata<=0){
                printf("真数必须大于0\n");
                break;
                }
                result = calc_log(idata);
                printf("calc log (%f) result is %f\n",idata,result);
	            break;

            case 12:
                if(idata<=0){
                printf("真数必须大于0\n");
                break;
                }
                result = calc_log10(idata);
                printf("calc log10 (%f) result is %f\n",idata,result);
                break;
            default:
		if(calc_mod==1)
                    printf("add 格式：./calc_sim 1 xxx xxx\n");
                if(calc_mod==2)
                    printf("sub 格式：./calc_sim 2 xxx xxx\n");
                if(calc_mod==3)
                    printf("multi 格式:./calc_sim 3 xxx xxx\n");
                if(calc_mod==4)
                    printf("div 格式:./calc_sim 4 xxx xxx\n");
                if(calc_mod==5)
                    printf("PI 格式:./calc_sim 5\n");
                if(calc_mod==6)
                    printf("sin 格式:./calc_sim 6 xxx\n");
                if(calc_mod==7)
                    printf("cos 格式:./calc_sim 7 xxx\n");
                if(calc_mod==8)
                    printf("tan 格式:./calc_sim 8 xxx\n");
                if(calc_mod==9)
                    printf("fabs 格式:./calc_sim 9 xxx\n");
                if(calc_mod==10)
                    printf("exp 格式:./calc_sim 10 xxx\n");
                if(calc_mod==11)
                    printf("log 格式:./calc_sim 11 xxx\n");
                if(calc_mod==12)
                    printf("log10 格式:./calc_sim 12 xxx\n");
                if(calc_mod==13)
                    printf("pow 格式:./calc_sim 13 xxx xxx\n");
                if(calc_mod==14)
                    printf("rand 格式:./calc_sim 14\n");
                
                break;
        }
	}

    if(argc==4){

        argv ++;
        idata = atof(*argv);
        argv ++;    
        kdata = atof(*argv);    
    
        printf("Enter is mod<%d> data_f<%f> data_b<%f> \n", calc_mod, idata, kdata);
    
        switch(calc_mod)
        {
    	    case 1:
    	        result = calc_add(idata, kdata);   
                printf("Calc add (%f + %f) result is %f\n", idata, kdata, result);  	    	
    	        break;
    	    	
    	    case 2:
    	        result = calc_sub(idata, kdata);
                printf("Calc sub (%f - %f) result is %f\n", idata, kdata, result);     	    	    
    	        break;
    	    
	        case 3:
	            result = calc_multi(idata,kdata);
	            printf("calc multi(%f * %f) result is %f\n",idata,kdata,result);
	            break;
		
	        case 4:
                if(kdata==0){
                    printf("除数不能为0\n");
                    break;}
                else
	            result = calc_div(idata,kdata);
	            printf("calc div(%f / %f) result is %f\n",idata,kdata,result);             
	            break;

            case 13:
                result = calc_pow(idata,kdata);
                printf("calc pow (%f , %f) result is %f\n",idata,kdata,result);
                break;

            default:
		if(calc_mod==1)
                    printf("add 格式：./calc_sim 1 xxx xxx\n");
                if(calc_mod==2)
                    printf("sub 格式：./calc_sim 2 xxx xxx\n");
                if(calc_mod==3)
                    printf("multi 格式:./calc_sim 3 xxx xxx\n");
                if(calc_mod==4)
                    printf("div 格式:./calc_sim 4 xxx xxx\n");
                if(calc_mod==5)
                    printf("PI 格式:./calc_sim 5\n");
                if(calc_mod==6)
                    printf("sin 格式:./calc_sim 6 xxx\n");
                if(calc_mod==7)
                    printf("cos 格式:./calc_sim 7 xxx\n");
                if(calc_mod==8)
                    printf("tan 格式:./calc_sim 8 xxx\n");
                if(calc_mod==9)
                    printf("fabs 格式:./calc_sim 9 xxx\n");
                if(calc_mod==10)
                    printf("exp 格式:./calc_sim 10 xxx\n");
                if(calc_mod==11)
                    printf("log 格式:./calc_sim 11 xxx\n");
                if(calc_mod==12)
                    printf("log10 格式:./calc_sim 12 xxx\n");
                if(calc_mod==13)
                    printf("pow 格式:./calc_sim 13 xxx xxx\n");
                if(calc_mod==14)
                    printf("rand 格式:./calc_sim 14\n");
    	     
    	        break;
        }
    }
    
    return 0;
}
