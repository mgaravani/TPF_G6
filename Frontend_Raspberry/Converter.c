#include <stdio.h>
#include <unistd.h>
#include "disdrv.h"
#include "joydrv.h"
#include <stdlib.h>
#include <time.h>

#define THRESHOLD 100
#define DISP_CANT_X_DOTS 16
#define DISP_CANT_Y_DOTS 16

int main()
{

    joy_init();                 // Inicializa el joystick
    disp_init();                // Inicializa el display
    disp_clear();               // Limpia todo el display
    joyinfo_t info;
    dcoord_t myPoint;
    int matriz[DISP_CANT_Y_DOTS][DISP_CANT_X_DOTS];

    // Inicializa la semilla del generador de números aleatorios
    srand(time(NULL));

    // Rellenar la matriz con 0 y 1 de forma aleatoria
    for (int i = 0; i < DISP_CANT_Y_DOTS; i++) {
        for (int j = 0; j < DISP_CANT_X_DOTS; j++) {
            matriz[i][j] = rand() % 2;
        }
    }

    // Imprimir la matriz en el formato solicitado
    printf("int matriz[FILAS][COLUMNAS] = {\n");
    for (int i = 0; i < DISP_CANT_Y_DOTS; i++) {
        printf("    {");
        for (int j = 0; j < DISP_CANT_X_DOTS; j++) {
            printf("%d", matriz[i][j]);
            if (j < DISP_CANT_X_DOTS - 1) {
                printf(", ");
            }
        }
        printf("}");
        if (i < DISP_CANT_Y_DOTS - 1) {
            printf(",");
        }
        printf("\n");
    }
    printf("};\n");

    // Recorrer la matriz y actualizar el display según el valor de cada elemento
    for (uint8_t i = 0; i < DISP_CANT_Y_DOTS; i++) {
        for (uint8_t j = 0; j < DISP_CANT_X_DOTS; j++) {
            myPoint.x = j;
            myPoint.y = i;
            if (matriz[i][j] == 1) {
                disp_write(myPoint, D_ON);   // Prende el LED en la posición (i, j)
            } else {
                disp_write(myPoint, D_OFF);  // Apaga el LED en la posición (i, j)
            }
            
            disp_update();  // Actualiza el display
        }
    }

    do
	{
		info = joy_read();				//las guardo en info
		
	} while (info.sw == J_NOPRESS);	//mientras no se presione el switch
    
    
    disp_clear();
    disp_update();

    return 0;
}
