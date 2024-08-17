#include <stdio.h>
#include <unistd.h>
#include "disdrv.h"
#include "joydrv.h"
#define THRESHOLD 100
#define FILAS 16
#define COLUMNAS 16

int main()
{
    joy_init();										//inicializa el joystick
	disp_init();									//inicializa el display
	disp_clear();									//limpia todo el display
    void disp_write(dcoord_t coord, dlevel_t val);
    dcoord_t pos = {DISP_MAX_X>>1 , 0 };	//pos es la posición actual, empieza en el centro de la parte inferior
	dcoord_t npos = pos;
    joyinfo_t coord = {0,0,J_NOPRESS};
    int matriz[FILAS][COLUMNAS];

    // Inicializa la semilla del generador de números aleatorios
    srand(time(NULL));

    // Rellenar la matriz con 0 y 1 de forma aleatoria
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            matriz[i][j] = rand() % 2;
        }
    }

    // Imprimir la matriz en el formato solicitado
    printf("int matriz[FILAS][COLUMNAS] = {\n");
    for (int i = 0; i < FILAS; i++) {
        printf("    {");
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%d", matriz[i][j]);
            if (j < COLUMNAS - 1) {
                printf(", ");
            }
        }
        printf("}");
        if (i < FILAS - 1) {
            printf(",");
        }
        printf("\n");
    }
    printf("};\n");

    return 0;
    
    disp_clear();
    disp_update();

    return 0;
}