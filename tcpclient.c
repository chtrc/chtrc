#include"myinclude.h"

#define SERVPORT 2888
#define MAXDATASIZE 100

int main()
{
	int sockfd;
	int recvbytes;
	char buf[MAXDATASIZE];
	struct hostent *host;
	struct sockaddr_in serv_addr;

	if((sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1){
		perror("socket");
		exit(1);
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(SERVPORT);
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	bzero(&(serv_addr.sin_zero),8);

	if(-1 == (connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(struct sockaddr)))){
		perror("connect");
		exit(1);
	}
	
	if(-1 == (recvbytes = recv(sockfd,buf,MAXDATASIZE,0))){
		perror("recv");
		exit(1);
	}
	buf[recvbytes] = 0;
	printf("Receved: %s",buf);

	close(sockfd);

	return 0;
}
