#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DEFAULT_PORT1 5051
int udp_server()
{
	FILE *pFile;

	int sPort = DEFAULT_PORT1;
	int sSocket = 0;
	int sLen = 0;
	int sSend = 0;
	int sRecv = 0;
	char send_buf[4096] = { 0 };
	char recv_buf[4096] = { 0 };
	struct sockaddr_in ser;
	struct sockaddr_in cli;

	printf("Server waiting...\n");

	sSocket = socket(AF_INET, SOCK_DGRAM, 0);
	if (sSocket < 0) {
		printf("socket() failure!\n");
		return -1;
	}

	ser.sin_family = AF_INET;
	ser.sin_port = htons(sPort);
	ser.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(sSocket, (struct sockaddr *) &ser, sizeof(ser)) < 0) {
		printf("bind() failure!\n");
		return 0;
	}

	sLen = sizeof(cli);
	memset(recv_buf, 0, sizeof(recv_buf));

	while (1) {
		pFile = fopen("movielist.txt", "r");
		if (fgets(send_buf, sizeof(send_buf), pFile) != NULL)
			if (fgets(send_buf, sizeof(send_buf), pFile) !=
			    NULL)

				sRecv =
				    recvfrom(sSocket, recv_buf, 4096, 0,
					     (struct sockaddr *) &cli,
					     (unsigned int *) &sLen);
		if ((sRecv < 0) || (sRecv == 0)) {
			printf("recvfrom() failure!\n");
			break;
		} else {
			printf("recvfrom(): [%s]\n", recv_buf);
			printf("recvfrom() client IP: [%s]\n",
			       inet_ntoa(cli.sin_addr));
			printf("recvfrom() client PORT: [%d]\n",
			       ntohs(cli.sin_port));
		}

		{
			if (strcmp(send_buf, recv_buf) == 0)
				strcpy(send_buf,
				       "The Movielist.txt is not changed!");
			else
				strcpy(send_buf,
				       "The Movielist.txt is changed!");
		}

		sSend =
		    sendto(sSocket, send_buf, sizeof(send_buf), 0,
			   (struct sockaddr *) &cli, sizeof(cli));

		if ((sSend < 0) || (sSend == 0)) {
			printf("sendto() failure!\n");
			break;
		}
		printf("sendto() Succeeded!\n");
		fclose(pFile);
	}

	close(sSocket);
	return 0;

}
