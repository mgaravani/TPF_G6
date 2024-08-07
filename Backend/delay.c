#include <stdio.h>
#include <time.h>
#define NIVELES 5

int tiempoespera (int nivel, int fila);
//  falta chequeo de errores
int main() {
    int nivel = 1;
    int fila = 1;

    // Ejemplo de uso
    while (1)
    {
        if (tiempoespera(nivel, fila)) {
        printf("Tiempo transcurrido suficiente.\n");
        } 
        //else {
        //    printf("Tiempo insuficiente.\n");
        //}
    }
    return 0;
}


int tiempoespera (int nivel, int fila){
    static clock_t flags[NIVELES];  //Guardo por nivel el tiempo de inicio.
    clock_t tiempo_actual;
    double tiempo_transcurrido;
    double vel;

    if (fila <= 5 && fila >= 1){
        vel = 1;
    }
    else if (fila >= 7 && fila <= 11){
        vel = 1.25;
    }

    if (flags[nivel] == 0){ //Inicio el tiempo la 1ra vez que se entra con un nivel
        flags[nivel] = clock();
    }

    tiempo_actual = clock(); //Guardo el tiempo actual para hacer luego la resta y fijarme el tiempo transcurrido
    tiempo_transcurrido = ((double)(tiempo_actual-flags[nivel]))/CLOCKS_PER_SEC;
    if (tiempo_transcurrido < (1/(nivel*vel))){//Me fijo si transcurrió un tiempo determinado
        return 0; //Si no transcurrio el tiempo, devuelvo 0
    }
    
    flags[nivel] = clock(); //Seteo un nuevo valor inicial
    return 1; // Si transcurrio el tiempo, devuelvo 1
}