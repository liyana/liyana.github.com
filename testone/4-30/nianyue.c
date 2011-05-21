#include <stdio.h>

int main(int argc, const char *argv[])
{
	int year, month, day, i, n = 0;
	int a[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int b[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	scanf("%d,%d,%d", &year, &month, &day);

	if (year < 0)
		printf("输入年份不合法\n");

	else {
		if ((year % 4 == 0 && year % 100 != 0)
		    || (year % 400 == 0)) {
			for (i = 0; i < month - 1; i++)
				n += a[i];
		} else {
			for (i = 0; i < month - 1; i++)
				n += b[i];
		}
		n += day;
		printf("是%d年中的第%d天\n", year, n);
	}
	return 0;
}
