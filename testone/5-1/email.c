#include <stdio.h>
#include <string.h>


char str[1023] = { 0 };

void get_email(const char str[]);
void get_email(const char str[])
{
	int i, flag = 0;
	int c = 0, m = 0;
	char a[1023] = { 0 };
	char b[1023] = { 0 };
	char str1[1023] = { 0 };
	char str2[1023] = { 0 };
	char str3[1023] = { 0 };
	for (i = 0; str[i]!='\n'; i++) {
		if (str[i] == '@')
			m++;
	}
      start:while (m) {
		int j, k = 0, n = 0, h = 0, t = 0;
		for (i = 0; i < 1023; i++) {
			str1[i] = 0;
			str2[i] = 0;
			str3[i] = 0;
			a[i] = 0;

		}

		for (i = c; str[i] != '@' && i < 1023 && str[i] != '\n';
		     i++) {
			a[n] = str[i];
			n++;
			c++;

		}

		if (n == 0 || str[c + 1 - n] == '@') {
			c++;
			m--;
			goto start;
		}


		for (j = n - 1; j >= 0 ; j--) {
			if (a[j] >= '0' && a[j] <= '9' || a[j] >= 'a'
			    && a[j] <= 'z' || a[j] >= 'A' && a[j] <= 'Z'
			    || a[j] == '.' || a[j] == '_') {
				str3[k] = a[j];
				k++;
			} else
				break;
		}

		for (i = k - 1; i >= 0; i--) {
			str1[h] = str3[i];
			h++;
		}

		if (h > 0 && h <=32) {
			str1[h] = '@';
			str1[h + 1] = '\0';
			for (j = c + 1;
			     j < 1023  && str[j] != '\n'
			     && str[i] != '@'; j++) {
				if (str[j] >= '0' && str[j] <= '9'
				    || str[j] >= 'a' && str[j] <= 'z'
				    || str[j] >= 'A' && str[j] <= 'Z'
				    || str[j] == '.' || str[j] == '-') {
					str2[t] = str[j];
					t++;
					c++;

				} else
					break;
			}

		}
		if (t == 0) {
			c++;
			m--;
			goto start;
		}

		if (t > 0 && t <= 64)
			str2[t] = '\0';

		if ((h > 0 && h <= 32) && (t > 0 && t <= 64))
			printf("%s\n", strcat(str1, str2));
		m--;
	}
}



int main(int argc, const char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	while (!feof(file)) {
               str[0]='\n';
		fgets(str, sizeof(str), file);
		get_email(str);
         // printf("%s\n",str);
	}

	fclose(file);
}
