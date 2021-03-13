/******************************************************
 * Project:         Práctica 1 de Sistemas Operativos II
 * 
 * Program name:    demonio.c
 * 
 * Author:          Pedro Millán Alvarez
 *
 * Purpose:         Programa en segundo plano que realiza una copia de seguirad cada minutp
 * 
 ******************************************************/
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void manejador(int sig);

int main(){
    signal(SIGINT, &manejador);
    mkdir("estudiantes_copia_seguridad",0777);
    while(1){
        sleep(60);
        system("cp -r estudiantes estudiantes_copia_seguridad");
    }
    return 0;
}

void manejador(int sig){
    printf("Señal recibido en demonio");
    exit(0);

}
