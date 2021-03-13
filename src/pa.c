#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>

#define FICHERO "./Ficheros/estudiantes.txt"

char* leerFichero();
char* obtenerDNI(char* cadena);
void crearDirectorio(char* DNI);
void escribirLog(char* texto);
void manejador(int sig);


int main(){

    signal(SIGINT, &manejador);
    leerFichero();
    escribirLog("Creación directorios finalizada\n");
    return 0;
    
}

char* leerFichero(){
    char linea[1024];
    FILE *fich;
    char* DNI;
    fich = fopen(FICHERO, "r");

    while(fgets(linea, 1024, (FILE*) fich)){

        DNI= obtenerDNI(linea);
        crearDirectorio(DNI);
    }
    return "FIN";
}

char* obtenerDNI(char* cadena){
    char delimitador[] = " ";
    char *token = strtok(cadena, delimitador);
    return token;

}
void  crearDirectorio(char* DNI){
    char command[80]="estudiantes/";
    strcat(command, DNI);
    //printf("%s\n", command);
    mkdir("estudiantes", 0777);
    mkdir(command,0777);
    
}
void escribirLog(char* texto){
    FILE *fich;
    if((fich = fopen("log.txt", "a"))== NULL){
        perror("Error al leer fichero log");
    }
    fputs(texto,fich);
    fclose(fich);

}
void manejador(int sig){
    printf("Señal recibido en A");
    exit(0);

}