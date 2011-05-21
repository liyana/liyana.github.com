#include <stdio.h>
void bubble(int a[],int n){
   int i,j,t;
        for (i = 0; i < n; i++)
             for (j = i + 1; j < 10; j++)
                  if (a[i] >= a[j]) {
                       t = a[i];
                        a[i] = a[j];
                         a[j] = t;
                     }


}
int main(int argc, const char *argv[])
{   int n=10;
    int i;
	int a[10] = { 1, 3, 2, 4, 5, 7, 8, 9, 0, 6 };
/*
	for (i = 0; i < 10; i++)
		for (j = i + 1; j < 10; j++)
			if (a[i] >= a[j]) {
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}*/
      
      bubble(a,10);
	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");

}
