#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char *argv[])
{
	int i, j;
	int a[1000] = { 0 };
	int b[10] = { 0 };
	for (i = 0; i < 1000; i++)

		for (j = 0; j < 10; j++) 
                 {
			a[i] = rand() % 10;
			if (a[i] == j)
				b[j]++;
		}

	for (j = 0; j < 10; j++)
		printf("%d\n", b[j]);

	return 0;
}
