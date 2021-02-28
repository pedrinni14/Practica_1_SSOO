#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char* leerFichero();
char* ObtenerDNI(char* cadena);
void CrearDirectorio(char* DNI);


int main(){

    printf(leerFichero());
    
}

char* leerFichero(){
    char linea[1024];
    FILE *fich;
    char* DNI;
    fich = fopen("estudiantes_p1.text", "r");

    while(fgets(linea, 1024, (FILE*) fich)){

        DNI= ObtenerDNI(linea);
        CrearDirectorio(DNI);
    }
    return "FIN";
}

char* ObtenerDNI(char* cadena){
    char delimitador[] = " ";
    char *token = strtok(cadena, delimitador);
    return token;

}
void  CrearDirectorio(char* DNI){
    char command[80]="mkdir estudiantes/";
    strcat(command, DNI);
    printf("%s\n", command);
    system("mkdir estudiantes");
    system(command);
    
}