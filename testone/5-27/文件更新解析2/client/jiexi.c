#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[40];
	char director[60];
	char year[30];

} List;
List li[100];

void get_Movielist(char cbuf[])
{
	static int i = 0;

	if (strncmp(cbuf, "Name @:", 7) == 0) {
		strcpy(li[i].name, cbuf);
	}

	if (strncmp(cbuf, "Director @:", 11) == 0) {
		strcpy(li[i].director, cbuf);
	}

	if (strncmp(cbuf, "Year @:", 7) == 0) {
		strcpy(li[i].year, cbuf);
		i++;
	}

}

int listName()
{
	int i;
	for (i = 0; i < 100; i++)
		printf("%s", li[i].name);
	printf("\n");
	return 0;
}

int listDirector()
{
	int i, j;
	printf("%s", li[0].director);
	for (j = 0; j < 10; j++)
		for (i = j - 1; i >= 0; i--) {
			if (strcmp(li[j].director, li[i].director) == 0)
				break;
			if (i == 0)
				printf("%s", li[j].director);
		}
	printf("\n");
	return 0;
}

int accordingtoYear()
{
	int m;
	char a[20] = "Year @: ";
	char s[10];

	printf("Input the year:");
	scanf("%s", s);
	strcat(a, s);
	for (m = 0; m < 100; m++) {

		if (strncmp(li[m].year, a, 12) == 0) {

			printf("%s", li[m].name);
			printf("%s", li[m].director);

		}
	}
	printf("\n");
	return 0;
}

int accordingtoDirector()
{
	int i;
	char b[40] = "Director @: ";
	char s[20];
	printf("Input the Director_name:");
	scanf("%s", s);
	strcat(b, s);

	for (i = 0; i < 100; i++) {
		if (strncmp(li[i].director, b, strlen(b)) == 0) {
			printf("%s", li[i].name);
			printf("%s", li[i].year);
		}
	}
	printf("\n");
	return 0;

}

int display()
{
	int i;
	for (i = 0; i < 100; i++) {
		printf("%s", li[i].name);
		printf("%s", li[i].director);
		printf("%s", li[i].year);
	}
	printf("\n");
	return 0;
}

int jiexi()
{
	int a;
	char cbuf[1024] = { 0 };
	FILE *pFile = fopen("movielist.txt", "r");
	while (!feof(pFile)) {
		cbuf[0] = '\0';
		fgets(cbuf, sizeof(cbuf), pFile);

		get_Movielist(cbuf);
	}

	while (1) {
		printf("1.listName\n");
		printf("2.listDirector\n");
		printf("3.accordingtoYear\n");
		printf("4.accordingtoDirector\n");
		printf("5.Display all\n");
		printf("6.Exit\n");
		printf("Please choose:");
		scanf("%d", &a);
		switch (a) {
		case 1:
			listName();
			break;

		case 2:
			listDirector();
			break;

		case 3:
			accordingtoYear();
			break;

		case 4:
			accordingtoDirector();
			break;

		case 5:
			display();
			break;
		case 6:
			return -1;
		default:
			break;
		}

	}
	return 0;
}
