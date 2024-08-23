/* INCLUDES */
#include <stdint.h>
#include <stdio.h>  // Incluyo la librería estándar stdio HOLA RAMA
#include <unistd.h> // Para la función sleep 
#include <stdio.h>  // Incluyo la librería estándar stdio
#include <unistd.h> // Para la función sleep
#include "logica.h"

uint32_t matriz[FILAS][COLUMNAS] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 6, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 8, 0, 0, 0, 8, 0, 0, 0, 8, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 9, 0, 0, 9, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 10, 0, 0, 0, 0, 10, 0, 0, 0, 0, 10, 0, 0, 10, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 11,0, 0, 0, 11, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 12, 0, 0, 0, 12, 0, 0, 0, 0, 0, 12, 0, 12, 0, 0, 12, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

AllegroResources iniciar_logica(void){
  return init_allegro(matriz);
}

void actualizar_pantalla(void){
  inicio_partida(matriz);
}
void imprimir_matriz(int filas, int columnas, int fila_index) {
    if (fila_index == -1) { // Imprimir toda la matriz
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                printf("%d ", matriz[i][j]);
            }
            printf("\n");
        }
    } else if (fila_index >= 0 && fila_index < filas) {
        // Imprimir una fila específica
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[fila_index][j]);
        }
        printf("\n");
    } else {
        printf("Índice de fila fuera de rango.\n");
    }
}

// Función para desplazar la matriz hacia derecha o izquierda. Recibe la direccion y numero de fila (row).
void shift_row(int row, int direction)
{
    if (direction) // Desplazar a la derecha
    {
        // Guardamos el último valor de la fila
        int ultimo_valor = matriz[row][COLUMNAS - 1];

        // Desplazamos todos los elementos hacia la derecha
        for (int i = COLUMNAS - 1; i > 0; i--)
        {
            matriz[row][i] = matriz[row][i - 1];
        }

        // Colocamos el valor del final al principio si era un punto válido
        if (ultimo_valor != 0)
        {
            matriz[row][0] = ultimo_valor;
        }
        else
        {
            matriz[row][0] = 0; // Limpiamos la primera columna si no hay punto
        }
    }
    else // Desplazar a la izquierda
    {
        // Guardamos el primer valor de la fila
        int primer_valor = matriz[row][0];

        // Desplazamos todos los elementos hacia la izquierda
        for (int i = 0; i < COLUMNAS - 1; i++)
        {
            matriz[row][i] = matriz[row][i + 1];
        }

        // Colocamos el valor del principio al final si era un punto válido
        if (primer_valor != 0)
        {
            matriz[row][COLUMNAS - 1] = primer_valor;
        }
        else
        {
            matriz[row][COLUMNAS - 1] = 0; // Limpiamos la última columna si no hay punto
        }
    }

    /* actualizar_pantalla(); */
}
// Funcion para actualizar matriz de mapa desplazando vehiculos
void update_map(int level)
{
    
}