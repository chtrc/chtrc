#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#define BUFSIZE 512
void copy(char *from,char *to)
{
	int fromid = -1,tofd = -1;
	ssize_t nread;
	char buf[BUFSIZE];
	if(-1==(fromid=open(from,O_RDONLY))){
		perror("open");
		exit(1);
	}
	if(-1==(tofd = open(to,O_WRONLY | O_CREAT | O_TRUNC,S_IRUSR | S_IWUSR))){
		perror("open to");
		exit(1);
	}
	nread = read(fromid,buf,sizeof(buf));
	while(nread > 0){
		if(write(tofd,buf,nread)!=nread)
			printf("write %s error\n",to);
		nread = read(fromid,buf,sizeof(buf));
	}
	close(fromid);
	close(tofd);
	exit(0);
}
int main(int argc,char **argv)
{
	if(argc!=3){
		printf("invalid parameter\n");
		exit(1);
	}
	copy(argv[1],argv[2]);

}
