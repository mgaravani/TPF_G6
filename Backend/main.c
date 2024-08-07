/* INCLUDES */
#include <stdio.h>  // Incluyo la librería estándar stdio
#include "../Frontend_Allegro/allegro.h" // Incluyo el archivo de cabecera de Allegro
#include <unistd.h> // Para la función sleep
#include "logica.h"

/* FUNCION MAIN */
int main(void) {
    for (int i = 0; i < 40; i++) {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    shift_row(2, 0);
    shift_row(3, 1);
    imprimir_matriz( FILAS, COLUMNAS, 2);
    imprimir_matriz( FILAS, COLUMNAS, 3);
    usleep(500000); 
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    shift_row(2, 0);
    shift_row(3, 1);
    imprimir_matriz( FILAS, COLUMNAS, 2);
    imprimir_matriz( FILAS, COLUMNAS, 3);
    usleep(500000);
    }
    return 0;
}