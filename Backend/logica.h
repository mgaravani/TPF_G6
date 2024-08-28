#ifndef LOGICA_H
#define LOGICA_H

#define FILAS 14
#define COLUMNAS 40
#include <stdint.h>  //Incluyo la libreria estandar para tener tipo de datos multiplataforma
#include "../Frontend_Allegro/allegro.h"

void desplazar_fila_izq( int fila_index, int desplazamientos);
void desplazar_fila_der( int fila_index, int desplazamientos);
void imprimir_matriz(int filas, int columnas, int fila_index);
AllegroResources iniciar_logica(void);

/*     PRUEBA DE MOVIMIENTO CONTINUO      */

/*     PRUEBA DE MOVIMIENTO CONTINUO      */
void actualizar_pantalla(void);
void shift_row(int row, int direction);
#endif /* ALLEGRO_H */