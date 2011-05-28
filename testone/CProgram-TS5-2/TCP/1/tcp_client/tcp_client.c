/* client_tcp.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DEFAULT_PORT 5050

int main(int argc, char** argv)
{   FILE * pFile;
    int cPort = DEFAULT_PORT;
    int cClient = 0;
    int cLen = 0;
    struct sockaddr_in cli;
    char cbuf[4096] = {0};
   
    if(argc < 2)
    {
        printf("Uasge: client[server IP address]\n");
        return -1;
    }
   
    memset(cbuf, 0, sizeof(cbuf));
   
    cli.sin_family = AF_INET;     //IPv4 Internet protocols
    cli.sin_port = htons(cPort);
    cli.sin_addr.s_addr = inet_addr(argv[1]);
   
     pFile = fopen ("2.txt","w");

while(1){

    cClient = socket(AF_INET, SOCK_STREAM, 0);

    if(cClient < 0)
    {
        printf("socket() failure!\n");
        return -1;
    }
   
    if(connect(cClient, (struct sockaddr*)&cli, sizeof(cli)) < 0)//成功返回0
    {
        printf("connect() failure!\n");
        return -1;
    }
   
    cLen = recv(cClient, cbuf, sizeof(cbuf),0);   
    if((cLen < 0)||(cLen == 0))
    {
          printf("recv() failure!\n");
        return -1;
    }

     fputs (cbuf,pFile );
  
} 

  fclose(pFile);
  close(cClient);
   
    return 0;
}
