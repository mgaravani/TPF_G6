/* INCLUDES */
#include <stdio.h>  // Incluyo la librería estándar stdio HOLA RAMA
#include <unistd.h> // Para la función sleep 
#include "logica.h"

// Macros para definir hasta que columna se shiftea antes de reiniciarse //
#define START_PRINT 2  
#define STOP_PRINT 37

int matriz[FILAS][COLUMNAS] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 6, 6, 6, 6, 0, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 0, 0, 7, 7, 7, 0, 0, 0, 0, 0, 0, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 11, 11, 11, 0, 11, 11, 11, 0, 0, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 12, 0, 0, 0, 0, 0, 0, 12, 12, 12, 0, 0, 0, 0, 0, 12, 12, 12, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

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
  if (direction) // Si direction distinto de 0, tomamos la direccion hacia la derecha
  {
    for (int i = COLUMNAS - 1; i > 0; i--) // Copio el elemento y se lo asigno al anterior
    {
      matriz[row][i] = matriz[row][i - 1];
    }
    if (matriz[row][STOP_PRINT] == row) // Reinicio la matriz cuando llega a un cierto limite y vuelve a comenzar
    {
      matriz[row][STOP_PRINT] = 0;
      matriz[row][START_PRINT] = row;
    }
  }
  else 
  {
    for (int i = 0; i < COLUMNAS - 1; i++) // Copio el elemento y se lo asigno al siguiente
    {
      matriz[row][i] = matriz[row][i + 1];
    }
    if (matriz[row][START_PRINT] == row) // Reinicio la matriz cuando llega a un cierto limite y vuelve a comenzar
    {
      matriz[row][START_PRINT] = 0;
      matriz[row][STOP_PRINT] = row;
    }
  }
}

// Funcion para actualizar matriz de mapa desplazando vehiculos
void update_map(int level)
{
    
}