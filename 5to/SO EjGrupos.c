#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/wait.h>

int main(int argc, char **argv){
    int arg = 12;
    int pid[arg];
    pid [0] = getpid();
    int id_grupo = 0;
    int num_proceso=0;

    struct sembuf operacion;
    key_t llave;
    int semid;
    
    llave = ftok (argv[0], 'K');
    if ((semid = semget (llave, 3, IPC_CREAT | 0600)) == -1){
        perror ("semget");
        exit (-1);
    }

    semctl (semid, 0,SETVAL,2);
    semctl (semid, 1,SETVAL,0);
    semctl (semid, 2,SETVAL,0); // Padre

    for (int i = 1; i <= arg; i++){
        if (getpid() == pid[0]){
            if((pid[i] = fork()) == 0){
                id_grupo = i%2;
                num_proceso = i;
            }
        }
    }
    
    if (getpid()==pid[0]){  // Padre
        int aux=0;
        while((semctl(semid, 0, GETNCNT)>0) && (semctl(semid, 1, GETNCNT)>0)){
            operacion.sem_flg = 0;
            operacion.sem_num = 2;
            operacion.sem_op = -2;
            semop (semid, &operacion, 1);
            if (aux) aux--;
            else aux++;
            operacion.sem_num = aux;
            operacion.sem_op = 2;
            semop (semid, &operacion, 1);
        }
        wait(0);
        semctl (semid,0,IPC_RMID,0);
    }
    else{   // Procesos hijos
        operacion.sem_flg = 0;
        operacion.sem_num = id_grupo;
        operacion.sem_op = -1;
        //printf("Proceso: %d Semaforo: %d\n",j,semctl(semid, j, GETVAL));
        semop (semid, &operacion, 1);
        printf("Hola soy proceso: %d Grupo: %d Pid: %d\n", num_proceso, id_grupo, getpid());
        //printf("Proceso: %d Semaforo: %d\n",j,semctl(semid, j, GETVAL));

        operacion.sem_num = 2;
        operacion.sem_op = 1;
        semop (semid, &operacion, 1);
    }
   
    return 0;
}
