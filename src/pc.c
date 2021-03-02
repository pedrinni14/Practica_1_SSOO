#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>



char* leerFichero();
char* obtenerDNI(char* cadena);
void escribirMedia(char* DNI, char* nota);
float calcularMediaTotal();
void escribirFichero(char* ruta, char* mensaje);


int main(int argc, char *argv[]){
    char media_cadena[32];
    char* fin;
    leerFichero();
    float media = calcularMediaTotal();
    sprintf(media_cadena,"%.2f", media);
    write(atoi(argv[0]), media_cadena, strlen(media_cadena)+1);

    return 0;
    
}

char* leerFichero(){
    char linea[1024];
    FILE *fich;
    char* DNI;
    fich = fopen("estudiantes_p1.text", "r");

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
    sprintf(text,"%d",media);
    strcat(mensaje,text);
    strcat(ruta,DNI);
    strcat(ruta,fichero);
    escribirFichero(ruta,mensaje);
    printf("%s\n", ruta);
}
float calcularMediaTotal(){
    char linea[1024];
    FILE *fich;
    fich = fopen("estudiantes_p1.text", "r");

    float suma = 0.0;
    while(fgets(linea, 1024, (FILE*) fich)){
        suma = suma + atof((linea+10));
        
    }
    return (suma/15);

}
void escribirFichero(char* ruta, char mensaje[100]){
    FILE *fich;
    fich = fopen(ruta, "w");
    
    fprintf(fich, mensaje);
    fclose(fich);
}