#include <stdio.h>
#include <string.h>
char str[1023] = { 0 };

void jiexi(const char str[]);
void jiexi(const char str[])
{
	int i, m;
	int c = 0, j = 0, k = 0, n = 0, h = 0, l = 0, t = 0;

	char str1[1023] = { 0 };	//命令数组 j
	char str2[1023] = { 0 };	//参数数组 k
	char str3[1023] = { 0 };	//文件名数组 t
	char str4[1023] = { 0 };	//in-file h
	char str5[1023] = { 0 };	//out-file l

	for (i = 0; i < 1023 && str[i] != '\n'; i++) {
		str1[i] = 0;
		str2[i] = 0;
		str3[i] = 0;
		str4[i] = 0;
		str5[i] = 0;
	}			//数组清零

	for (i = 0; i < 1023 && str[i] != '\n'; i++) {

		if (str[i] == ' ')
			c++;
		else
			break;
	}			//找命令前的空格


	for (i = c; i < 1023 && str[i] != '\n'; i++) {
		if (str[i] == ' ')
			break;
		str1[j] = str[i];
		j++;
		c++;
	}			//把命令拷贝到数组str1  

	for (i = c; i < 1023 && str[i] != '\n'; i++) {
		if (str[i] == ' ')
			c++;
		else
			break;
	}			//继续找命令后空格

	m = c;			//暂存c的值

	/*for (i = c; i < 1023 && str[i] != '\n'; i++) {
	   if (str[i] == '-')
	   n++;
	   else
	   break;
	   }                    //找命令行一共有多少个 -，那就应该有多少个参数

	   while (n) {
	   for (i = c; str[i] != '-' && i < 1023 && str[i] != '\n';
	   i++) {
	   c++;
	   }            //找到第一个'-'

	   for (i = c + 1; str[i] != '\n' && i < 1023; i++) {
	   if (str[i] == ' ')
	   break;
	   str2[k] = str[i];
	   k++;
	   c++;
	   }            //将参数拷贝到数组 str2
	   str2[k]=' ';
	   n--;
	   }                    //所有的参数全部找完，并全拷贝到数组 str2

	 */

	i = m;
	while (str[i] != '\n' && i < 1023) {
		if (str[m] == '-') 
              {

			for (i = m + 1; str[i] != '\n' && i < 1023; i++) {
				if (str[i] == ' ')
					break;
				str2[k] = str[i];
				k++;
				m++;
			}	//将参数拷贝到数组 str2
			str2[k++] = ' ';

			for (i = m + 1; str[i] != '\n' && i < 1023; i++) {
				if (str[i] == ' ')
					m++;
				else
					break;
			}	//继续找空格

		}

             else
		if (str[m] == '<') {
			for (i = m + 1; str[i] != '\n' && i < 1023; i++) {
				if (str[i] == ' ')
					m++;
				else
					break;
			}	//继续找空格

			for (i = m + 1; str[i] != '\n' && i < 1023; i++) {
				if (str[i] == ' ')
					break;
				str4[h] = str[i];
				h++;
				m++;
			}	//把<后的内容拷贝到数组str4 
                       

                     for (i = m + 1; str[i] != '\n' && i < 1023; i++) {
				if (str[i] == ' ')
					m++;
				else
					break;
			}	//继续找空格
		}


               else
		if (str[m] == '>') {
			for (i = m + 1; str[i] != '\n' && i < 1023; i++) {
				if (str[i] == ' ')
					m++;
				else
					break;
			}	//继续找空格

			for (i = m + 1; str[i] != '\n' && i < 1023; i++) {
				if (str[i] == ' ')
					break;
				str5[l] = str[i];
				l++;
				m++;
			}	//把>后的内容拷贝到数组str5

                      for (i = m + 1; str[i] != '\n' && i < 1023; i++) {
				if (str[i] == ' ')
					m++;
				else
					break;
			}	//继续找空格

		}
                  else 
		      if (str[m] != '>' && str[m] != '<' && str[m] != '\n'
		    && str[m] != '-' && str[m]!='\0') {
                  

			for (i = m; str[i] != '\n' && i < 1023; i++) {
				if (str[i] == ' ')
					break;
				str3[t] = str[i];
				t++;
				m++;
			}	//把文件名拷贝到数组str3

			for (i = m; str[i] != '\n' && i < 1023; i++) {
				if (str[i] == ' ')
					m++;
				else
					break;
			}	//继续找空格

		}
               
	}


str1[j]='\0';
str2[k]='\0';
str3[t]='\0';
str4[h]='\0';
str5[l]='\0';


	if (strlen(str1) != 0)
		printf("命令：%s ", str1);
	if (strlen(str2) != 0)
		printf("参数：%s ", str2);
	if (strlen(str3) != 0)
		printf("文件名：%s ", str3);
	if (strlen(str4) != 0)
		printf("in-file：%s ", str4);
	if (strlen(str5) != 0)
		printf("out-file：%s ", str5);
	printf("\n");

}


int main(int argc, const char *argv[])
{
	FILE *file = fopen("1.txt", "r");
	while (!feof(file)) {
		str[0] = '\n';
		fgets(str, sizeof(str), file);
		jiexi(str);
	}

	fclose(file);
	return 0;
}
