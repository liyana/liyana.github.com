#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char *argv[])
{
	int i, j;
	int b[10] = { 0 };
	int a[1000] = { 0 };
	for (i = 0; i < 1000; i++)
		a[i] = rand() % 10;

	for (i = 0; i < 1000; i++)
		switch (a[i]) {
		case 0:
			b[0]++;
			continue;
		case 1:
			b[1]++;
			continue;
		case 2:
			b[2]++;
			continue;
		case 3:
			b[3]++;
			continue;
		case 4:
			b[4]++;
			continue;
		case 5:
			b[5]++;
			continue;
		case 6:
			b[6]++;
			continue;
		case 7:
			b[7]++;
			continue;
		case 8:
			b[8]++;
			continue;
		case 9:
			b[9]++;
			continue;
		}
	for (j = 0; j < 10; j++)
		printf("%d\n", b[j]);
	return 0;
}
