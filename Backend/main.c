/* INCLUDES */
#include <stdio.h>  // Incluyo la librería estándar stdio
#include "allegro.h" // Incluyo el archivo de cabecera de Allegro
#include <unistd.h> // Para la función sleep
#include "logica.h"

/* FUNCION MAIN */
int main(void) {
    for (int i = 0; i < 40; i++) {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    desplazar_fila_izq(1, 1);
    desplazar_fila_der(3, 1);
    desplazar_fila_izq(5, 1);
    desplazar_fila_der(7, 1);
    desplazar_fila_izq(9, 1);
    desplazar_fila_der(11, 1);
    
    imprimir_matriz( FILAS, COLUMNAS, 1);
    imprimir_matriz( FILAS, COLUMNAS, 3);
    imprimir_matriz( FILAS, COLUMNAS, 5);
    imprimir_matriz( FILAS, COLUMNAS, 7);
    imprimir_matriz( FILAS, COLUMNAS, 9);
    imprimir_matriz( FILAS, COLUMNAS, 11);
    usleep(500000); 
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    desplazar_fila_izq(1, 1);
    desplazar_fila_der(3, 1);
    desplazar_fila_izq(5, 1);
    desplazar_fila_der(7, 1);
    desplazar_fila_izq(9, 1);
    desplazar_fila_der(11, 1);
    imprimir_matriz( FILAS, COLUMNAS, 1);
    imprimir_matriz( FILAS, COLUMNAS, 3);
    imprimir_matriz( FILAS, COLUMNAS, 5);
    imprimir_matriz( FILAS, COLUMNAS, 7);
    imprimir_matriz( FILAS, COLUMNAS, 9);
    imprimir_matriz( FILAS, COLUMNAS, 11);
    usleep(500000);
    }
    return 0;
}