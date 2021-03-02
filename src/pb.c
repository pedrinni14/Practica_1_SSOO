#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* leerFichero();
void copiarTipoEx(char tipo , char* DNI);
char* obtenerDNI(char* cadena);

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
        copiarTipoEx(linea[9], DNI);
        
       
    }
    return "FIN";
}

void copiarTipoEx(char tipo , char* DNI){

    if (tipo=='A'){
        char command[80]="cp ./MODELOSEXAMEN/MODELOA.pdf estudiantes/";
        strcat(command, DNI);
        //printf("%s\n", command);
        system(command);

    }
    if (tipo=='B'){
        char command[80]="cp ./MODELOSEXAMEN/MODELOB.pdf estudiantes/";
        strcat(command, DNI);
        //printf("%s\n", command);
        system(command);

    }
    if (tipo=='C'){
        char command[80]="cp ./MODELOSEXAMEN/MODELOC.pdf estudiantes/";
        strcat(command, DNI);
        //printf("%s\n", command);
        system(command);
    }

}
char* obtenerDNI(char* cadena){
    char delimitador[] = " ";
    char *token = strtok(cadena, delimitador);
    return token;

}