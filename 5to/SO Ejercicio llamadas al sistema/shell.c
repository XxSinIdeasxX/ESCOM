#include<stdio.h>
#include<unistd.h>

int main(void){
    int estado;
    char programa[20];
    printf("> ");
    scanf("%s",programa);
    while(programa[0] != '0'){
        if (fork()==0){
            estado = execl(programa,0);
            printf("Error en %s => %d\n", programa, estado);
            _exit(1);
        }else{
            printf("> ");
            scanf("%s", programa);
        }
    }
    return 0;
}