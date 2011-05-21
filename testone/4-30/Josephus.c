#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char *argv[])
{

	int t = 0, count = 0, i;
	// int m=3,n=100;
	int m = atoi(argv[2]), n = atoi(argv[1]);
	int a[100];
	for (i = 0; i < n; i++)
		a[i] = 1;
	while (t < n) {
		for (i = 0; i < n; i++) {
			if (a[i] != 0)
				count++;
			if (count == m) {
				a[i] = 0;
				count = 0;
				t++;
				printf("%3d: %3d out ", t, i + 1);
				if (t % 6 == 0)
					printf("\n");
			}

		}
	}
	printf("\n");
	return 0;
}
