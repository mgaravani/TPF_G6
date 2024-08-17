#include <stdio.h>
#include <unistd.h>
#include "disdrv.h"
#include "joydrv.h"
#include <stdlib.h>
#include <time.h>

#define DISP_CANT_X_DOTS 16
#define DISP_CANT_Y_DOTS 16

// Función para generar la matriz con valores aleatorios de 0 y 1
void generar_matriz(int matriz[DISP_CANT_Y_DOTS][DISP_CANT_X_DOTS]) {
    srand(time(NULL));

    for (int i = 0; i < DISP_CANT_Y_DOTS; i++) {
        for (int j = 0; j < DISP_CANT_X_DOTS; j++) {
            matriz[i][j] = rand() % 2;
        }
    }
}

// Función para leer la matriz y actualizar el display
void mostrar_matriz(int matriz[DISP_CANT_Y_DOTS][DISP_CANT_X_DOTS]) {
    dcoord_t myPoint;

    for (uint8_t i = 0; i < DISP_CANT_Y_DOTS; i++) {
        for (uint8_t j = 0; j < DISP_CANT_X_DOTS; j++) {
            myPoint.x = j;
            myPoint.y = i;
            if (matriz[i][j] == 1) {
                disp_write(myPoint, D_ON);
            } else {
                disp_write(myPoint, D_OFF);
            }
            disp_update();
        }
    }
}

int main() {
    joy_init();
    disp_init();
    disp_clear();

    int matriz[DISP_CANT_Y_DOTS][DISP_CANT_X_DOTS];
    joyinfo_t info = {0,0,J_NOPRESS};
    time_t start_time, current_time;

    // Obtén el tiempo de inicio
    start_time = time(NULL);

    do {
        info = joy_read();  // Lee el estado del joystick
        if (info.sw != J_NOPRESS) {  // Si se detecta una pulsación
            generar_matriz(matriz);  // Genera una nueva matriz
            mostrar_matriz(matriz);  // Muestra la nueva matriz en el display
        }

        // Obtén el tiempo actual
        current_time = time(NULL);

    } while (difftime(current_time, start_time) < 20);  // Ejecuta hasta que hayan pasado 20 segundos

    // Limpiar y finalizar
    disp_clear();
    disp_update();
    printf("Han pasado 20 segundos. El programa se terminará.\n");

    return 0;
}
