#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
 
struct sigaction capturador_SIGINT;
struct sigaction capturador_SIGILL;
struct sigaction capturador_SIGTERM;
struct sigaction capturador_SIGFPE;
struct sigaction capturador_SIGUSR1;

void captura_SIGINT(){
    printf("\nProceso %i: señal SIGINT recibida\n", getpid());
}

void captura_SIGILL(){
    printf("\nProceso %i: señal SIGILL recibida\n", getpid());
}

void captura_SIGTERM(){
    printf("\nProceso %i: señal SIGTERM recibida\n", getpid());
}

void captura_SIGFPE(){
    printf("\nProceso %i: señal SIGFPE recibida\n", getpid());
}

void captura_SIGUSR1(){
    printf("\nProceso %i: señal SIGUSR1 recibida\n", getpid());
}

int main(void){
    capturador_SIGINT.sa_handler = captura_SIGINT;
    sigaction (SIGINT, &capturador_SIGINT, NULL);

    capturador_SIGILL.sa_handler = captura_SIGILL;
    sigaction (SIGILL, &capturador_SIGILL, NULL);

    capturador_SIGTERM.sa_handler = captura_SIGTERM;
    sigaction (SIGTERM, &capturador_SIGTERM, NULL);

    capturador_SIGFPE.sa_handler = captura_SIGFPE;
    sigaction (SIGFPE, &capturador_SIGFPE, NULL);

    capturador_SIGUSR1.sa_handler = captura_SIGUSR1;
    sigaction (SIGUSR1, &capturador_SIGUSR1, NULL);

    int pid;
    if(pid=fork()==0){
        while(1){
            printf("\nProceso %i a la espera de señales\n", getpid());
            pause();
        }
    }
    sleep(3);
    kill(pid, SIGINT);
    
    sleep(3);
    kill(pid, SIGILL);

    sleep(3);
    kill(pid, SIGTERM);

    sleep(3);
    kill(pid, SIGFPE);

    sleep(3);
    kill(pid, SIGUSR1);
    exit(0);
}