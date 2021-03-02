#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char* leerFichero();
char* obtenerDNI(char* cadena);
void crearDirectorio(char* DNI);


int main(){

    leerFichero();
    return 0;
    
}

char* leerFichero(){
    char linea[1024];
    FILE *fich;
    char* DNI;
    fich = fopen("estudiantes_p1.text", "r");

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
    char command[80]="mkdir estudiantes/";
    strcat(command, DNI);
    //printf("%s\n", command);
    system("mkdir estudiantes");
    system(command);
    
}