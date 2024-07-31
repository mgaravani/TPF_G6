/* INCLUDES */
#include <stdio.h>  // Incluyo la librería estándar stdio
#include "allegro.h" // Incluyo el archivo de cabecera de Allegro

/* FUNCION MAIN */
int main(void) {
    printf("Hola");
    AllegroResources resources = init_allegro();

    draw_text(resources, 0, "Texto con fuente 1", 400, 300); // Muestra el texto con la primera fuente
    al_rest(3); // Pausa para ver el resultado
    draw_text(resources, 2, "Texto con fuente 2", 400, 300);
    al_rest(3); // Pausa para ver el resultado
    cleanup_allegro(resources);

    return 0;
    
    /*char word[] = "palabra";
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
    } */
}
