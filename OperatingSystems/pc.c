#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

int main()
{
    int semid1, semid2,shmid,data_length=25,*a,*b;
	struct sembuf increament, decreament;

    semid1 = semget(IPC_PRIVATE, 1, 0777|IPC_CREAT);
	semid2 = semget(IPC_PRIVATE, 1, 0777|IPC_CREAT);
	shmid = shmget(IPC_PRIVATE, sizeof(int), 0777|IPC_CREAT);

    semctl(semid1, 0, SETVAL, 0);
	semctl(semid2, 0, SETVAL, 1);

    increament.sem_num=decreament.sem_num=0;
	increament.sem_flg=decreament.sem_flg=0;
	decreament.sem_op=-1;
    increament.sem_op=1;

    if (!fork())
    {
        a=(int *)shmat(shmid, 0, 0);

        while (data_length)
        {
            semop(semid1,&decreament,1);
            printf("consumer reads %d\n",*a);
            semop(semid2,&increament,1);
            data_length--;
        }
        shmdt(a);
    }
    else
    {
        b=(int *)shmat(shmid, 0, 0);

        while (data_length)
        {
            semop(semid2,&decreament,1);
            *b=26-data_length;
            printf("producer produces %d\n",*b);
            semop(semid1,&increament,1);
            data_length--;
        }
        shmdt(b);
    }


    return 0;
}

