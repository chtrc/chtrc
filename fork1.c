#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	pid_t id;
	if((id=fork())==-1){ //returns -1 when failed,returns 0 in child, returns child's pid in parent
		perror("fork");
		exit(1);
	}
	if(id == 0){
		printf("i'm child process\n");
	}	
	else printf("i'm parent process\n");
	printf("%d\n",getpid());

}
