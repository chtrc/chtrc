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
int main()
{
	return 0;
}
