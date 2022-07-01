#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sem.h>
#include <sys/ipc.h>

int main(int argc, char **argv){
    int arg = atoi(argv[1]);
    int pid[arg];
    pid [0] = getpid();
    
    struct sembuf operacion;
    key_t llave;
    int semid=0;

    llave = ftok (argv[0], 'K');
    if ((semid = semget (llave, arg, IPC_CREAT | 0600)) == -1){
        perror ("semget");
        exit (-1);
    }

    semctl (semid,0,SETVAL,1);
    for(int i=1; i<arg;i++)
        semctl (semid, i,SETVAL,0);
    
    printf("Hola soy proceso: 0 con el pid: %d\n", getpid())

    int j = 0; 
    for (int i = 1; i < arg; i++){
        if (getpid() == pid[0]){
            if((pid[i] = fork()) == 0) j=i;
        }
    }

    operacion.sem_flg = 0;
    operacion.sem_num = j ;
    operacion.sem_op = -1;
    semop (semid, &operacion, 1);
    printf("Hola soy proceso: %d con el pid: %d\n", j, getpid());
    operacion.sem_num = j+1;
    operacion.sem_op = 1;
    if (i==arg-1)operacion.sem_num = 0;                
    semop (semid, &operacion, 1);
    
    
    /*
    if (getpid() == pid[0]){
        printf("\nPadre:\n");
        for (int i = 0; i < arg; i++){
            printf("Proceso: %d con el pid: %d\n",i , pid[i]);
        }
    }
    */
    semctl (semid,0,IPC_RMID,0);
    return 0;
}
