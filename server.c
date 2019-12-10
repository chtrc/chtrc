#include"myinclude.h"

#define SERVPORT 8888

int main()
{
	int sockfd;
	struct sockaddr_in serv_addr,client_addr;
	pid_t pid;

	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd == -1){
		perror("sock");
		exit(1);
	}

	char ip_serv[20];
//	printf("input server ip:%s",ip_serv);
	setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(serv_addr));
	
	bzero(&(serv_addr),sizeof(struct sockaddr_in));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(SERVPORT);
	serv_addr.sin_addr.s_addr = inet_addr(ip_serv);

	int opt = SO_REUSEADDR;
	bind()
//	printf("%d %d %d ",sizeof(long),sizeof(unsigned long),sizeof(unsigned short));
//	printf("%d",sizeof(short));
	
}
