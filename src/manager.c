/******************************************************
 * Project:         Práctica 1 de Sistemas Operativos II
 * 
 * Program name:    manager.c
 * 
 * Author:          Pedro Millán Alvarez
 *
 * Purpose:         Creación y gestión de los procesos pa , pb , pc , pd , manejo de la señal y la ejecución del demonio 
 * 
 ******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <time.h>
#include <string.h>

#define ESCRITURA 1
#define LECTURA 0 

void manejador(int sig);
void escribirLog(char* texto);

int main(){
    char *const parmList[] = {NULL, NULL, NULL};
    char *const envParms[] = {NULL};


    pid_t pid_a,pid_b,pid_c;
    int status_a,status_b,status_c;
    int tuberia[2];
    char wr_tuberia[256];
    char buffer[32];
    FILE* fich;
    escribirLog("*** LOG DEL SISTEMA ****\n");

    pipe(tuberia);
    signal(SIGINT, &manejador);
    sprintf(wr_tuberia, "%d", tuberia[ESCRITURA]);
    system("./exec/demonio &");
    if((pid_a = fork())== 0){
        // Codigo proceso PA

        if(execve("./exec/pa", parmList, envParms)== -1){
            perror("Error en la ejecución");
            exit(1);
        }
    }
    else if(pid_a == -1) {
        perror("Error en la creación del proceso A");
        exit(1);

    }
    else {

        waitpid(pid_a,&status_a,0);

        if (pid_b = fork()== 0){
            //Codigo del proceso PB
            if(execve("./exec/pb", parmList, envParms)== -1){
            perror("Error en la ejecución");
            exit(1);
            }
        }else if (pid_b==-1){
            perror("Error con el proceso PB");
            exit(1);

        }else if(pid_c = fork()== 0){
            //Codigo del proceso PC
            if(execl("./exec/pc", wr_tuberia , NULL)== -1){
            perror("Error en la ejecución");
            exit(1);
            }
        }else if(pid_c==-1) {
            perror("Error con el proceso PC");
            exit(1);
        }
        else{
            //Codigo del padre
            wait(&status_b);
            wait(&status_c);
            read(tuberia[LECTURA],buffer, sizeof(buffer));
            escribirLog("La nota media de la clase es: ");
            escribirLog(buffer);
            escribirLog("\nFIN DEL PROGRAMA\n");
        }
        



    }



}
void manejador(int sig){

    int pid_d;
    int status_d;
    FILE *fich;
    

    if((pid_d=fork())==0){

        if(execl("./exec/pd", NULL , NULL)== -1){
            perror("Error en la ejecución");
            exit(1);
        }
    

    }else{
        fich = fopen("log.txt", "a");
        escribirLog("Interrupción ejecutada a proposito \n");
        wait(&status_d);
        exit(0);
    }
}

void escribirLog(char* texto){
    FILE *fich;
    if((fich = fopen("log.txt", "a"))== NULL){
        perror("Error al leer fichero log");
    }
    fputs(texto,fich);
    fclose(fich);

}

