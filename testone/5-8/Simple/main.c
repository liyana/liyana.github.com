#include <stdio.h>
#include "d2b.h"
#include "multi.h"
#include "exchange.h"
#include "encryption.h"
#include "common.h"
#include <stdlib.h>
int main(int argc, const char *argv[])
{
	int i;
	while (1) {
        
		printf("1.decimal to binary\n");
		printf("2.x*y\n");
		printf("3.low or up exchange\n");
		printf("4.encryption\n");
		printf("5.Exit\n");

		printf("please choose [1-5]:\n");
		scanf("%d", &i);
		switch (i) {
		case 1:
			d2b(); empty_cache();
			break;
		case 2:
			multi();empty_cache();
			break;
		case 3:
			exchange();empty_cache();
			break;
		case 4:
			encryption();empty_cache();
			break;
		case 5:
			exit(0);
			break;
		}
		return 0;
	}
}

/*int erjinzhixianshi()
{
	int flag = 0;
	int i, a;
	printf("输入一个整型数：\n");
	scanf("%d", &a);
	for (i = 31; i >= 0; i--)
		if ((a >> i) & 1 == 1 || flag == 1) {
			flag = 1;
			if (flag)
				printf("%d ", (a >> i) & 1);
		}
}

int chengfa()
{
	int i, x, y, ax, ay, result = 0, flag = 0;
      start:printf("输入两个整型数：\n");
	if (2 != scanf("%d %d", &x, &y))
		goto start;

	if ((x >> 31) & 1)
		ax = ~(x - 1);
	else
		ax = x;
	if ((y >> 31) & 1)
		ay = ~(y - 1);
	else
		ay = y;
	if (((x >> 31) & 1) ^ ((y >> 31) & 1))
		flag = 1;
	for (i = 0; i < 31; i++)
		if ((ay >> i) & 1)
			result += ax << i;
	if (flag)
		result = ~result + 1;
	printf("%d * %d =%d", x, y, result);
}

int daxiaoxie()
{
	char a[] = { 0 };
	printf(" 输入要转换的字符串：\n");
	scanf("%s", a);
	int i;
	for (i = 0; a[i] != '\0'; i++) {
		if (a[i] >= 'A' && a[i] <= 'Z')
			a[i] |= 32;
		else if (a[i] >= 'a' && a[i] <= 'z')
			a[i] &= 223;
	}
	printf("%s\n", a);
	return 0;
}

int jiami()
{
	char a[] = { 0 };
	printf("输入需要加密的：\n");
	scanf("%s", a);
	int i, c = 9;
	for (i = 0; a[i] != '\0'; i++)
		a[i] ^= c;
	printf("加密后：%s\n", a);
	for (i = 0; a[i] != '\0'; i++)
		a[i] ^= c;
	printf("解密后：%s\n", a);

	return 0;

}*/
