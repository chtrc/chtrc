#include"myinclude.h"

union semum{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo *_buf;
};
int P(int semid,int semnum)
{
	struct sembuf sops = {
		semnum,
		-1,
		SEM_UNDO
	};
	return (semop(semid,&sops,1));
}
int V(int semid,int semnum)
{
	struct sembuf sops = {
		semnum,
		1,
		SEM_UNDO
	};
	return (semop(semid,&sops,1));
}
int main(int argc,int **argv)
{
	int key,rt;
	int semid,ret;
	union semun arg;
	struct sembuf semop;
	int flag;

	if(argc > 2 || (argc == 2 && strcmp("del",argv[1])!=0)){
		printf("invalid usage\n");
		return -1;
	}
	key = ftok("/tmp",0x66);
	if(key < 0){
		perror("ftok");
		return -1;
	}
	semid = semget(key,3,IPC_CREAT | 0600);
	printf("semid %d\n",semid);
	if(semid == -1){
		perror("semget");
		return -1;
	}

	if(argc == 1){
		arg.val = 1;
		ret = semctl(semid,0,SETVAL,1);
		if(ret < 0){
			perror("semctl");
			rt = semctl(semid,0,IPC_RMID);
			if(rt == -1){
				perror("semctl");
			}
			else{
				printf("semaphore %d deleted!\n",semid);
				return -1;
			}
		}
		ret = semctl(semid,0,GETVAL,arg);
		printf("after semctl setval sem[0].val=[%d]\n",ret);
		system("date");
	}
	/*
	 *
	 * todo....
	 *
	 * */
	return 0;
}
