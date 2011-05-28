#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define DEFAULT_PORT1 5051
int udp_client(char *y)
{
	FILE *pFile;
	pFile = fopen("movielist.txt", "r");
	int flag;
	int cPort = DEFAULT_PORT1;
	int cClient = 0;
	unsigned int cLen = 0;
	int cSend = 0;
	int cRecv = 0;
	char send_buf[4096] = { 0 };
	char recv_buf[4096] = { 0 };
	struct sockaddr_in cli;

	memset(recv_buf, 0, sizeof(recv_buf));

	cli.sin_family = AF_INET;
	cli.sin_port = htons(cPort);
	cli.sin_addr.s_addr = inet_addr(y);

	cClient = socket(AF_INET, SOCK_DGRAM, 0);
	if (cClient < 0) {
		printf("socket() failure!\n");
		return -1;
	}

	cLen = sizeof(cli);

	if (fgets(send_buf, sizeof(send_buf), pFile) != NULL)
		if (fgets(send_buf, sizeof(send_buf), pFile) != NULL)
			cSend =
			    sendto(cClient, send_buf, sizeof(send_buf), 0,
				   (struct sockaddr *) &cli, cLen);
	if ((cSend < 0) || (cSend == 0)) {
		printf("sendto() failure!\n");
		return -1;
	} else {
		printf("sendto() succeeded.\n");
	}

	cRecv =
	    recvfrom(cClient, recv_buf, sizeof(recv_buf), 0,
		     (struct sockaddr *) &cli, (unsigned int *) &cLen);
	if ((cRecv < 0) || (cRecv == 0)) {
		printf("recvfrom() failure!\n");
		return -1;
	}
	if (strcmp(recv_buf, "The Movielist.txt is not changed!") == 0)
		flag = 0;
	if (strcmp(recv_buf, "The Movielist.txt is changed!") == 0)
		flag = 1;
	if (flag == 0)
		printf("目前没有更新!\n");
	if (flag == 1)
		printf("已有更新,请重新下载!\n");
	fclose(pFile);
	close(cClient);
	printf("\n");
	return 0;
}
