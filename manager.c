#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
    char *const parmList[] = {NULL, NULL, NULL};
    char *const envParms[] = {NULL};

    int status_a, status_b, status_c;
    pid_t pid_a,pid_b,pid_c, pid;


    if((pid_a = fork())== 0){
        // Aqui va el codigo relacionado con el codigo pa 

        printf("Funciona la creación de A \n");
        if(execve("./pa", parmList, envParms)== -1){
            perror("Error en la ejecución");
            exit(1);
        }
    }
    else if(pid_a == -1) {
        perror("Error en la creación del proceso A");
        exit(1);

    }
    else {

        wait(status_a);

        

        if (pid_b = fork()== 0){
            //Codigo del proceso PB
            printf("Funciona la creación del Proceso B \n");
            if(execve("./pb", parmList, envParms)== -1){
            perror("Error en la ejecución");
            exit(1);
            }
        }else if (pid_b==-1){
            perror("Error con el proceso PB");
            exit(1);

        }else if(pid_c = fork()== 0){
            //Codigo del proceso PC
            printf("Funciona la creación del Proceso C\n");
           
            if(execve("./pc", parmList, envParms)== -1){
            perror("Error en la ejecución");
            exit(1);
            }
        }else if(pid_c==-1) {
            perror("Error con el proceso PC");
            exit(1);
        }
        else{
            //Codigo del padre
            wait(status_b);
            wait(status_c);
        }
        



    }



}