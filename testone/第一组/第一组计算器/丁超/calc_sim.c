#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<assert.h>
#define PI 3.1415926

double calc_add(double a,double b)
{
	double s;
	s=a+b;
	return s;
}

double calc_sub(double a,double b)
{	
	double s;
	s = a-b;
	return s;
}
double calc_multi(double a,double b)
{	
	double s;
	s = a*b;
	return s;
}
double calc_div(double a,double b)
{
	double s;
	if(b!=0) 
	{s = a/b;
	return s;}
	else 
	{printf("input error\n");return 0;}
}
double calc_pi(double a)
{	
	double s;
	s = PI*a;
	return s;
}

double calc_sin(double a)
{	
	double s,b;
	b=(a*PI)/180;
	s = sin(b);
	return s;
}

double calc_cos(double a)
{ 
        double s,b;
	b=(a*PI)/180;
        s = cos(b);
        return s;
}
double calc_tan(double a)
{	int i;
	double s,b;
	for(i=1;i<100;i++)
	{if(a==(double)90*i){printf("input error\n");return -1;}
	else
	 b=(a*PI)/180;
	s=tan(b);}
	return s;
}
double calc_log(double a)
{	double s;
	if(a>0)
	{s= log(a);
	return s;}
	else {printf("input error\n");return 0;}
}
double calc_log10(double a)
{	double s;
	if (a>0)
	{s= log10(a);
	return s;}
	else {printf("input error\n");return 0;}
}
double calc_pow(double a,double b)
{	double s;
	s=pow(a,b);
	return s;
}
double calc_ran()
{	double s;
	srand( (unsigned)time( NULL ) );
	s = rand();
	return s;
}
double calc_fab(double a)
{	double s;
	s=fabs(a);
	return s;
}
	
double calc_en(double a)
{	double s;
	s=exp(a);
	return s;
}
	
int main(int argc, const char *argv[])
{	int  mod;
	double x,y,result;
	if(argc < 2)
	{
		printf("enter cmd numbers must > 2!!!\n");
		return 0;
	}
	
	argv ++;
	mod = atoi (*argv);
	if(argc >2)
	{argv ++;
        x = atof (*argv);
		if(argc==3)printf("Enter is mod<%d> x<%f> \n",mod, x);}
	if(argc >3)
	{argv ++;
        y = atof (*argv);
	if(argc==4)
	printf("Enter is mod<%d> x<%f> y<%f> \n",mod, x, y);}
	if(argc>4)
	printf("input error");
	switch (mod)
		{
		case 1:result =calc_add(x,y);
			printf("add (%f +%f ) result is %f\n",x,y,result);break;
		case 2:result = calc_sub(x,y);
                        printf("sub (%f -%f ) result is %f\n",x,y,result);break;
		case 3:result = calc_multi(x,y);
                        printf("multi (%f*%f) result is %f\n",x,y,result);break;
		case 4:result = calc_div(x,y); if(y!=0)
                        printf("div (%f/%f) result is %f\n",x,y,result);break;
		case 5:result = calc_pi(x);
                        printf("pi (%f) result is %f\n",x,result);break;

		case 6:result = calc_sin(x);
                        printf("sin (%f) result is %f\n",x,result);break;
		case 7:result = calc_cos(x);
                        printf("cos (%f) result is %f\n",x,result);break;
		case 8:result = calc_tan(x);if(result!=-1)
                        printf("tan (%f) result is %f\n",x,result);break;
		case 9:result = calc_fab(x);
			printf("fabs (%f) result is %f\n",x,result);break;
		case 10:result = calc_en(x);
                        printf("en (%f) result is %f\n",x,result);break;
		case 11:result = calc_log(x);if(x>0)
                        printf("log (%f) result is %f\n",x,result);break;
		case 12:result = calc_log10(x);if(x>0)
                        printf("log10 (%f) result is %f\n",x,result);break;
		case 13:result =calc_pow (x,y);
                        printf("pow (%f,%f) result is %f\n",x,y,result);break;
		case 14:result = calc_ran();
                        printf("rand() result is %f\n",result);break;
		default:printf("Enter calc mod error!\n");break;


		}
	return 0;
}
