// Fernando Rodríguez Calderón - Sistemas operativos

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#include<signal.h>

struct sigaction capturador_SIGTERM;
struct sigaction capturador_SIGUSR1;
struct sigaction capturador_SIGUSR2;

void captura_SIGTERM(){
    printf("\nProceso: %d", getpid());
    exit(0);
}

void captura_SIGUSR1(){
}

void leeCad(char *cad){
    int i;
    char aux;
    fflush(stdin);
    for(i=0; (aux=getchar())!='\n'; i++){
        cad[i]=aux;
    }
    cad[i]='\0';
}

int main(void){
    capturador_SIGTERM.sa_handler = captura_SIGTERM;
    sigaction (SIGTERM, &capturador_SIGTERM, NULL);
    
    capturador_SIGUSR1.sa_handler = captura_SIGUSR1;
    sigaction (SIGUSR1, &capturador_SIGUSR1, NULL);

    int fd, pid;
    char *aux;
    pid = getpid();

    while(1){
        if(fork()==0){
            pause();

            fd = open("doc.txt", O_WRONLY, 0666);
            read(fd, &aux, 4096);
            close(fd);

            printf("\nTexto leido: %s\n", aux);

            kill(pid, SIGUSR1);
            exit(0);

        }else{
            fd = creat("doc.txt",0666);
            sleep(2);
            printf("\n> ");
            leeCad(aux);

            write(fd, &aux, strlen(aux)*sizeof(char));
            close(fd);

            kill(0, SIGUSR1);
            pause();
        }
    } 
    return 0;
}