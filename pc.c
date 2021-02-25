#include<stdio.h>
#include<stdlib.h>
#include<string.h>



char* leerFichero();
char* ObtenerDNI(char* cadena);
void CrearFichero(char* DNI);
void EscribirMedia(char* DNI, char* nota);
float calcularMediaTotal();
void EscribirFichero(char* ruta, char* mensaje);


int main(){

    printf(leerFichero());
    float media = calcularMediaTotal();
    printf("%f ",media);
    
}

char* leerFichero(){
    char linea[1024];
    FILE *fich;
    char* DNI;
    fich = fopen("estudiantes_p1.text", "r");

    while(fgets(linea, 1024, (FILE*) fich)){

        DNI= ObtenerDNI(linea);
        CrearFichero(DNI);
        EscribirMedia(DNI,(linea+10));
    }
    fclose(fich);
    return "FIN \n ";

}

char* ObtenerDNI(char* cadena){
    char delimitador[] = " ";
    char *token = strtok(cadena, delimitador);
    return token;

}
void  CrearFichero(char* DNI){
    char command[80]="touch ./";
    strcat(command, DNI);
    strcat(command, "/nota_necesaria.txt");
    //printf("%s\n", command);
    system(command);
}
void EscribirMedia(char* DNI, char* nota){

    char mensaje[100]= "La nota que debes obtener en este nuevo examen para superar la prueba es ";
    int numero = atoi(nota);
    int media = 10-numero;
    char ruta[100]="./";
    char text[10];
    char* fichero = "/nota_necesaria.txt";
    sprintf(text,"%d",media);
    strcat(mensaje,text);
    strcat(ruta,DNI);
    strcat(ruta,fichero);
    EscribirFichero(ruta,mensaje);
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
void EscribirFichero(char* ruta, char mensaje[100]){
    FILE *fich;
    fich = fopen(ruta, "w");
    
    fprintf(fich, mensaje);
    fclose(fich);
}