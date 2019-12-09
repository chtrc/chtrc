#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<string.h>

#define MAXLINE 4096

int parse(char*,char**);
int main()
{
	pid_t pid;
	char *rt;
	char buf[MAXLINE];
	int status;
	char *args[64];
	int argnum = 0;

	while(1){
		printf("chh$ ");
		rt = fgets(buf,MAXLINE,stdin);
		if(rt == NULL){
			perror("fgets");
			exit(1);
		}
		if(!strcmp(buf,"\n")){
			printf("chh$ ");
			continue;
		}
		if(buf[strlen(buf) - 1] == '\n'){
			buf[strlen(buf - 1)] = 0;
		}
		argnum = parse(buf,args);
		if(strcmp(args[0],"logout") == 0 || strcmp(args[0],"exit") == 0){
			exit(0);
		}
		else{
			if((pid = fork()) == -1){
				perror("fork");
				exit(1);
			}
			else if(pid == 0){
				execvp(*args,args);
				printf("could't exec %s\n",buf);
			}
			else{
				if((pid = waitpid(pid,&status,0)) < 0 )
					printf("wait pid err\n");
			}
		}
	}
	exit(0);
}

int parse(char *buf, char **args)
{
	int num = 0;
	while(*buf != 0){
		while((*buf == ' ') || (*buf == '\t') || (*buf == '\n')){
			*buf++ = 0;
		}
		*args++ = buf;
		num++;
		while((*buf!='0')&&(*buf!=' ')&&(*buf!='\t')&&(*buf!='\n'))
			buf++;
	}
	*args = 0;
	return num;
}
