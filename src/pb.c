#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>

#define FICHERO "./Ficheros/estudiantes.txt"

char* leerFichero();
void copiarTipoEx(char tipo , char* DNI);
char* obtenerDNI(char* cadena);
void escribirLog(char* texto);
void manejador(int sig);

int main(){

    signal(SIGINT, &manejador);
    leerFichero();
    escribirLog("Copia de modelos de examen,finalizada\n");
    sleep(4);
    return 0;

}

char* leerFichero(){
    char linea[1024];
    FILE *fich;
    char* DNI;
    if((fich = fopen(FICHERO, "r")) == NULL){
        perror("Error en la apertura fichero");
    }

    while(fgets(linea, 1024, (FILE*) fich)){

        DNI= obtenerDNI(linea);
        copiarTipoEx(linea[9], DNI);
        
       
    }
    fclose(fich);
    return "FIN";
}

void copiarTipoEx(char tipo , char* DNI){

    if (tipo=='A'){
        char command[80]="ln ./Ficheros/MODELOSEXAMEN/MODELOA.pdf estudiantes/";
        strcat(command, DNI);
        strcat(command,"/MODELOA.pdf");
        system(command);

    }
    if (tipo=='B'){
        char command[80]="ln ./Ficheros/MODELOSEXAMEN/MODELOB.pdf estudiantes/";
        strcat(command, DNI);
        strcat(command,"/MODELOB.pdf");
        system(command);

    }
    if (tipo=='C'){
        char command[80]="ln ./Ficheros/MODELOSEXAMEN/MODELOC.pdf estudiantes/";
        strcat(command, DNI);
        strcat(command,"/MODELOC.pdf");
        system(command);
    }

}
char* obtenerDNI(char* cadena){
    char delimitador[] = " ";
    char *token = strtok(cadena, delimitador);
    return token;

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
    printf("Señal recibido en B");
    exit(0);

}