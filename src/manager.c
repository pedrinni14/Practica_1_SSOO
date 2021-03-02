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


int main(){
    char *const parmList[] = {NULL, NULL, NULL};
    char *const envParms[] = {NULL};


    pid_t pid_a,pid_b,pid_c, pid;
    int status_a,status_b,status_c;
    int tuberia[2];
    char wr_tuberia[256];
    char buffer[32];
    FILE *fich;
    fich = fopen("log.txt", "w");
    

    pipe(tuberia);
    signal(SIGINT, &manejador);
    sprintf(wr_tuberia, "%d", tuberia[ESCRITURA]);
    if((pid_a = fork())== 0){
        // Aqui va el codigo relacionado con el codigo pa 

        printf("Funciona la creación de A \n");
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
        fprintf(fich, "Creación directorios finalizada\n");
        

        

        if (pid_b = fork()== 0){
            //Codigo del proceso PB
            sleep(3);
            printf("Funciona la creación del Proceso B \n");
            if(execve("./exec/pb", parmList, envParms)== -1){
            perror("Error en la ejecución");
            exit(1);
            }
        }else if (pid_b==-1){
            perror("Error con el proceso PB");
            exit(1);

        }else if(pid_c = fork()== 0){
            //Codigo del proceso PC
            printf("Funciona la creación del Proceso C\n");
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
            fprintf(fich, "Copia de modelos de examen,finalizada\n");
            wait(&status_c);
            read(tuberia[LECTURA],buffer, sizeof(buffer));
            printf("%s",buffer);
            fprintf(fich, "Creación de archivos con nota necesaria para alcanzar la nota de corte, finalizada\n");
            fprintf(fich, "La nota media de la clase es: ");
            fprintf(fich, buffer);
            fprintf(fich,"\nFIN DE PROGRAMA");
            fclose(fich);
        }
        



    }



}
void manejador(int sig){

    int pid_d;
    int status_d;
    FILE *fich;
    fich = fopen("log.txt", "w");
    

    if((pid_d=fork())==0){

        if(execl("./exec/pd", NULL , NULL)== -1){
            perror("Error en la ejecución");
            exit(1);
        }
    

    }else{
        fprintf(fich, "Interrupción ejecutada a proposito\n");
        wait(&status_d);
        exit(1);
    }
}