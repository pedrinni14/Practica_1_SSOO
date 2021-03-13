#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){

    printf("Salida forzada, Archivos Eliminados.");
    system("rm -R estudiantes");

    return 0;
}