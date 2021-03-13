#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void manejador(int sig);

int main(){
    signal(SIGINT, &manejador);
    mkdir("estudiantes_copia_seguridad",0777);
    while(1){
        sleep(20);
        system("cp -r estudiantes estudiantes_copia_seguridad");
    }
    return 0;
}

void manejador(int sig){
    printf("Señal recibido en demonio");
    exit(0);

}
