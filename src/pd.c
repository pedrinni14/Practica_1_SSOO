/******************************************************
 * Project:         Práctica 1 de Sistemas Operativos II
 * 
 * Program name:    pd.c
 * 
 * Author:          Pedro Millán Alvarez
 *
 * Purpose:         Programa que se ejecuta cuando se produce una interrupción mediante control+C y elmina todos los archivos generados por los procesos pa pb pc  
 *
 ******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){

    printf("Salida forzada, Archivos Eliminados.");
    system("rm -R estudiantes");

    return 0;
}