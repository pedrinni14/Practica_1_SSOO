/******************************************************
 * Project:         Práctica 1 de Sistemas Operativos II
 * 
 * Program name:    pc.c
 * 
 * Author:          Pedro Millán Alvarez
 *
 * Purpose:         Calcula la nota media total de la clase, se la pasa al manager mediante una tubería y además escribe en un fichero txt en cada directorio de cada estudiante
 *                  la nota necesaria en el siguiente examen para aprobar la asignatura
 * 
 ******************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>

#define FICHERO "./Ficheros/estudiantes.txt"



char* leerFichero();
char* obtenerDNI(char* cadena);
void escribirMedia(char* DNI, char* nota);
float calcularMediaTotal();
void escribirLog(char* texto);
void escribirFichero(char* ruta, char* mensaje);
void manejador(int sig);


int main(int argc, char *argv[]){
    char media_cadena[32];
    char* fin;
    leerFichero();
    float media = calcularMediaTotal();
    sprintf(media_cadena,"%.2f", media);
    write(atoi(argv[0]), media_cadena, strlen(media_cadena)+1);
    escribirLog("Creación de archivos con nota necesaria para alcanzar la nota de corte, finalizada\n");

    return 0;
    
}

char* leerFichero(){
    char linea[1024];
    FILE *fich;
    char* DNI;

    if((fich = fopen(FICHERO, "r"))== NULL){
        perror("Error en la apertura fichero");
    };

    while(fgets(linea, 1024, (FILE*) fich)){

        DNI= obtenerDNI(linea);
        escribirMedia(DNI,(linea+10));
    }
    fclose(fich);
    return "FIN \n ";

}

char* obtenerDNI(char* cadena){
    char delimitador[] = " ";
    char *token = strtok(cadena, delimitador);
    return token;

}
void escribirMedia(char* DNI, char* nota){

    char mensaje[100]= "La nota que debes obtener en este nuevo examen para superar la prueba es ";
    int numero = atoi(nota);
    int media = 10-numero;
    char ruta[100]="./estudiantes/";
    char text[10];
    char* fichero = "/nota_necesaria.txt";
    signal(SIGINT, &manejador);
    sprintf(text,"%d",media);
    strcat(mensaje,text);
    strcat(ruta,DNI);
    strcat(ruta,fichero);
    escribirFichero(ruta,mensaje);
}
float calcularMediaTotal(){
    char linea[1024];
    FILE *fich;
    if((fich = fopen(FICHERO, "r"))== NULL){
        perror("Error en la apertura fichero");
    };

    float suma = 0.0;
    while(fgets(linea, 1024, (FILE*) fich)){
        suma = suma + atof((linea+10));
        
    }
    fclose(fich);
    return (suma/15);

}
void escribirLog(char* texto){
    FILE *fich;
    if((fich = fopen("log.txt", "a"))== NULL){
        perror("Error al leer fichero log");
    }
    fputs(texto,fich);
    fclose(fich);

}
void escribirFichero(char* ruta, char mensaje[100]){
    FILE *fich;
    if((fich = fopen(ruta, "w"))== NULL){
        perror("Error en la apertura fichero");
    }
    
    fprintf(fich, mensaje);
    fclose(fich);
}
void manejador(int sig){
    printf("Señal recibido en C");
    exit(0);

}
