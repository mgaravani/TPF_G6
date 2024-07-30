/* INCLUDES */
#include <stdio.h>  // Incluyo la librería estándar stdio
#include <string.h> // Incluyo la librería estándar string
#include "allegro.h" // Incluyo el archivo de cabecera de Allegro

/* FUNCION MAIN */
int main(void) {
    char word[] = "palabra";
    int var = 250;
    printf("%d \n", var);
    printf("%d\n", (int)strlen(word));

    pthread_t thread_id; 
    // Crear el hilo
    if (pthread_create(&thread_id, NULL, allegro, NULL)) {
        fprintf(stderr, "Error al crear el hilo.\n"); //Analizo si se crea correctamente
        return -1;
    }

    // Esperar a que el hilo termine
    if (pthread_join(thread_id, NULL)) {
        fprintf(stderr, "Error al esperar al hilo.\n"); //Analizo que el hilo termine correctamente
        return -1;
    }

    return 0;
}
