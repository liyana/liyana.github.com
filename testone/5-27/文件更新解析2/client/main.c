#include <stdio.h>
#include <stdlib.h>
#include "jiexi.h"
#include "tcp_client.h"
#include "udp_client.h"
int main(int argc, char *argv[])
{
	int c;
	char s[20] = { 0 };
	while (1) {
		printf("1.检查是否更新\n");
		printf("2.下载\n");
		printf("3.解析\n");
		printf("4.退出\n");
		printf("Please choose:");
		scanf("%d", &c);

		switch (c) {
		case 1:
			printf("\n请输入IP：");
			scanf("%s", s);
			udp_client(s);
			break;
		case 2:
			printf("\n请输入IP：");
			scanf("%s", s);
			tcp_client(s);
			break;
		case 3:
			jiexi();
			break;
		case 4:
			exit(0);
		default:
			break;

		}
	}
	return 0;
}
