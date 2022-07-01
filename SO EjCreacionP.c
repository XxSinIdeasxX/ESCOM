#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    int arg = atoi(argv[1]);

    int pid[arg];
    pid [0] = getpid();
    printf("Hola soy proceso padre con el pid: %d\n" , pid[0]);
    for (int i = 1; i < arg; i++){
        if (getpid() == pid[0]){
            if ((pid[i]=fork())==0){
                printf("Hola soy proceso: %d con el pid: %d\n",i , getpid()); 
            }
        }
    }
    if (getpid() == pid[0]){
        putchar("\n");
        for (int i = 0; i < arg; i++){
            printf("Proceso: %d Pid: %d\n",i , pid[i]);
        }
    }
    return 0;
}
