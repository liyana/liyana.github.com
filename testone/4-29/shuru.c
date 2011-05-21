#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i, j, n, m = 0, flag, k;
	int a[10] = { 0 };
	scanf("%d", &n);
	k = n;
	for (;; m++) {
		n /= 10;
		if (n == 0 && n % 10 == 0)
			break;
	}
        m++; 
	n = k;
	for (j = 0; j < m; j++) {
		a[j] = n % 10;
		n /= 10;
		if (n == 0 && n % 10 == 0)
			break;
	}

	flag = 0;
	{
		for (j = 0; j < m; j++)
			for (i = j + 1; i < m - 1; i++)
				if (a[j] == a[i]) {
					flag = 1;
					break;
				}

		if (flag)
			printf("有重复数字出现\n");
		else
			printf("无重复数字出现\n");
	}
	return 0;
}
