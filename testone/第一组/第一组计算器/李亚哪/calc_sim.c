/* calc_a_s.c */  
    
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include<time.h>
#define PI 3.141592653
/* add */ 
double calc_add(double a1, double a2) 
{
	
double result = 0;
	
result =  a1 + a2;
	
return result;

}

/* sub */ 
double calc_sub(double b1, double b2) 
{
double result = 0;

result = b1 - b2;
	
return (result);

}

/* multi */ 
double calc_multi(double c1, double c2) 
{
double result = 0;
	
result =  c1 *c2;
	
return (result);

}

/* div */ 
double calc_div(double d1, double d2) 
{
double result = 0;

result =  d1 / d2;

return (result);

}

 /*PI*/ 
double calc_PI() 
{
double result = 0;
	
result = PI;
	
return (result);

}

/*sin*/ 
double calc_sin(double e1) 
{
double result = 0;
	
result = sin(e1);
	
return (result);

}

/*cos*/ 
double calc_cos(double f1) 
{
double result = 0;
	
result = cos(f1);
	
return (result);

}

/*tan*/ 
double calc_tan(double g1) 
{
double result = 0;
	
result = tan(g1);
	
return (result);

}

/*abs*/ 
double calc_fabs(double h1) 
{
double result = 0;
	
result = fabs(h1);
	
return (result);

}

/*exp*/ 
double calc_exp(double t1) 
{
double result = 0;
	
result = exp(t1);
	
return (result);

}

/*log*/ 
double calc_log(double t1) 
{
double result = 0;
	
result = log(t1);
	
return (result);

}

/*log10*/ 
double calc_log10(double t1) 
{
double result = 0;

result = log10(t1);
	
return (result);

}

/*pow*/ 
double calc_pow(double t1, double t2) 
{
double result = 0;
	
result = pow(t1, t2);

return (result);

}

/*rand*/ 
double calc_rand() 
{
double result = 0;

srand((int)time(0));
	
result = rand();
	
return (result);

}

/* main */ 
int main(int argc, char **argv)	// Have Problems! Do you know why?
{
unsigned int calc_mod = 0;
	
double idata = 0;
	
double kdata = 0;
	
double result1 = 0;

if(argc<2||argc >4){
printf("1.加法运算：请输入两个操作数：\n");
printf("2.减法运算：请输入两个操作数：\n");
printf("3.乘法运算：请输入两个操作数：\n");
printf("4.除法运算：请输入两个操作数：\n");
printf("5.PI运算:无参数\n");
printf("6.sin运算：请输入一个操作数：\n");
printf("7.cos运算：请输入一个操作数：\n");
printf("8.tan运算：请输入一个操作数：\n");
printf("9.绝对值运算：请输入一个操作数：\n");
printf("10.幂指数运算：请输入一个操作数：\n");
printf("11.自然对数运算：请输入一个操作数：\n");
printf("12.常对数运算：请输入一个操作数：\n");
printf("13.n次幂运算：请输入两个操作数：\n");
printf("14.随机数运算：无参数\n");
return -1;
}


if(argc==2)
{argv++;
	
calc_mod = atoi(*argv);

if(calc_mod<1||calc_mod>14){printf("第一个参数不合法，范围应是1-14\n");return -1;}

switch (calc_mod)
 {
case 5:		
result1 = calc_PI();
		
printf("Calc PI result is %f\n", result1);		
break;

case 14:
result1 = calc_rand();
printf("Calc rand() result is %f\n", result1);
break;

default:
if(calc_mod==1)printf("1.加法运算：请输入两个操作数：\n");
if(calc_mod==2)printf("2.减法运算：请输入两个操作数：\n");
if(calc_mod==3)printf("3.乘法运算：请输入两个操作数：\n");
if(calc_mod==4)printf("4.除法运算：请输入两个操作数：\n");
if(calc_mod==5)printf("5.PI运算:无参数\n");
if(calc_mod==6)printf("6.sin运算：请输入一个操作数：\n");
if(calc_mod==7)printf("7.cos运算：请输入一个操作数：\n");
if(calc_mod==8)printf("8.tan运算：请输入一个操作数：\n");
if(calc_mod==9)printf("9.绝对值运算：请输入一个操作数：\n");
if(calc_mod==10)printf("10.幂指数运算：请输入一个操作数：\n");
if(calc_mod==11)printf("11.自然对数运算：请输入一个操作数：\n");
if(calc_mod==12)printf("12.常对数运算：请输入一个操作数：\n");
if(calc_mod==13)printf("13.n次幂运算：请输入两个操作数：\n");
if(calc_mod==14)printf("14.随机数运算：无参数\n");
break;
}

}

if(argc==3){
argv++;
	
calc_mod = atoi(*argv);

if(calc_mod<1||calc_mod>14){printf("第一个参数不合法，范围应是1-14\n");return 1;}
	
argv++;
	
idata = atof(*argv);

switch (calc_mod)
 {
case 6:
result1 = calc_sin(idata);
		
printf("Calc sin(%f) result is %f\n", idata, result1);
break;
	
case 7:
result1 = calc_cos(idata);
		
printf("Calc cos(%f) result is %f\n", idata, result1);
break;
	
case 8:

result1 = calc_tan(idata);
		
printf("Calc tan(%f) result is %f\n", idata, result1);
break;
	
case 9:
result1 = calc_fabs(idata);
		
printf("Calc fabs(%f) result is %f\n", idata, result1);		
break;
	
case 10:
result1 = calc_exp(idata);
		
printf("Calc exp(%f) result is %f\n", idata, result1);
break;
	
case 11:
if(idata<=0)
{printf("输入不合法\n");break;
}

result1 = calc_log(idata);
		
printf("Calc ln(%f) result is %f\n", idata, result1);
break;
	
case 12:
if(idata<=0)
{printf("输入不合法\n");break;
}

result1 = calc_log10(idata);
		
printf("Calc log10(%f) result is %f\n", idata, result1);
break;

default:
if(calc_mod==1)printf("1.加法运算：请输入两个操作数：\n");
if(calc_mod==2)printf("2.减法运算：请输入两个操作数：\n");
if(calc_mod==3)printf("3.乘法运算：请输入两个操作数：\n");
if(calc_mod==4)printf("4.除法运算：请输入两个操作数：\n");
if(calc_mod==5)printf("5.PI运算:无参数\n");
if(calc_mod==6)printf("6.sin运算：请输入一个操作数：\n");
if(calc_mod==7)printf("7.cos运算：请输入一个操作数：\n");
if(calc_mod==8)printf("8.tan运算：请输入一个操作数：\n");
if(calc_mod==9)printf("9.绝对值运算：请输入一个操作数：\n");
if(calc_mod==10)printf("10.幂指数运算：请输入一个操作数：\n");
if(calc_mod==11)printf("11.自然对数运算：请输入一个操作数：\n");
if(calc_mod==12)printf("12.常对数运算：请输入一个操作数：\n");
if(calc_mod==13)printf("13.n次幂运算：请输入两个操作数：\n");
if(calc_mod==14)printf("14.随机数运算：无参数\n");
break;

}

}

if(argc==4){
argv++;
	
calc_mod = atoi(*argv);
if(calc_mod<1||calc_mod>14){printf("第一个参数不合法，范围应是1-14\n");return -1;}	
argv++;
	
idata = atof(*argv);
	
argv++;	

kdata = atof(*argv);

	
printf("Enter is mod<%d> data_f<%f> data_b<%f> \n", calc_mod,
		  
idata, kdata);
	
switch (calc_mod)
 {
case 1:
result1 = calc_add(idata, kdata);

printf("Calc add (%f + %f) result is %f\n", idata, kdata,
			 
result1);
break;
	
case 2:
result1= calc_sub(idata, kdata);
	
printf("Calc sub (%f - %f) result is %f\n", idata, kdata,
			 
result1);
break;
	
case 3:
result1 = calc_multi(idata, kdata);
		
printf("Calc multi (%f * %f) result is %f\n", idata,
			 
kdata, result1);
break;
	
case 4:
if(kdata==0)
{printf("除数不能为0，输入不合法！！！\n");
break;
}

result1 = calc_div(idata, kdata);
		
printf("Calc div (%f / %f) result is %f\n", idata, kdata,
			 
result1);
break;
		
case 13:
result1 = calc_pow(idata,kdata);
		
printf("Calc pow(%f,%f) result is %f\n", idata, kdata,
			 
result1);
break;
		
default:
if(calc_mod==1)printf("1.加法运算：请输入两个操作数：\n");
if(calc_mod==2)printf("2.减法运算：请输入两个操作数：\n");
if(calc_mod==3)printf("3.乘法运算：请输入两个操作数：\n");
if(calc_mod==4)printf("4.除法运算：请输入两个操作数：\n");
if(calc_mod==5)printf("5.PI运算:无参数\n");
if(calc_mod==6)printf("6.sin运算：请输入一个操作数：\n");
if(calc_mod==7)printf("7.cos运算：请输入一个操作数：\n");
if(calc_mod==8)printf("8.tan运算：请输入一个操作数：\n");
if(calc_mod==9)printf("9.绝对值运算：请输入一个操作数：\n");
if(calc_mod==10)printf("10.幂指数运算：请输入一个操作数：\n");
if(calc_mod==11)printf("11.自然对数运算：请输入一个操作数：\n");
if(calc_mod==12)printf("12.常对数运算：请输入一个操作数：\n");
if(calc_mod==13)printf("13.n次幂运算：请输入两个操作数：\n");
if(calc_mod==14)printf("14.随机数运算：无参数\n");
break;
		
}

}
	
return 0;

}




