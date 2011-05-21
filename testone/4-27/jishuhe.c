#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i = 1;
	int sum = 0;
	while (i <= 100) {
		sum += i;
		i += 2;
	}
	printf("奇数和为：%d\n", sum);
	return 0;
}
