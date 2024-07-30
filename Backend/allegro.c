/* INCLUDES */
#include <stdio.h>  // Incluyo la librería estándar stdio
#include <allegro5/allegro.h> // Incluyo la librería Allegro
#include <allegro5/allegro_primitives.h> // Incluyo el addon primitives
#include <allegro5/allegro_font.h> // Incluyo el addon font
#include <allegro5/allegro_ttf.h>  // Incluye el addon para fuentes TTF
#include "allegro.h" // Incluyo el archivo header Allegro

/* FUNCION ALLEGRO */
void* allegro(void* arg)
{
    if (!al_init()) { // Inicio Allegro
        fprintf(stderr, "Error al inicializar Allegro!\n");
        pthread_exit(NULL);
    }

    if (!al_install_keyboard()) // Instalo el driver para el teclado
    {
        fprintf(stderr, "No se pudo crear instancia al teclado.\n");
        pthread_exit(NULL);
    }

    if (!al_init_font_addon()) // Inicio Allegro Fonts
    {
        fprintf(stderr, "Error al inicializar Allegro Fonts.\n");
        pthread_exit(NULL);
    }

    if (!al_init_primitives_addon()) // Inicio Allegro Primitives
    {
        fprintf(stderr, "Error al inicializar Allegro Primitives.\n");
        pthread_exit(NULL);
    }

    if (!al_init_ttf_addon()) {  // Inicializa el addon para fuentes TTF
        fprintf(stderr, "Error al inicializar Allegro TTF.\n");
        pthread_exit(NULL);
    }

    // Configura el display para pantalla completa
    al_set_new_display_flags(ALLEGRO_FULLSCREEN);

    // Verificar modos de pantalla compatibles
    ALLEGRO_DISPLAY_MODE disp_data;
    al_get_display_mode(0, &disp_data);
    int width = disp_data.width;
    int height = disp_data.height;
    printf("Resolución de pantalla detectada: %dx%d\n", width, height);

    ALLEGRO_DISPLAY *pantalla = al_create_display(width, height); // Creo la pantalla (puntero)
    if (!pantalla) // Veo si se creó correctamente
    {
        fprintf(stderr, "Error al crear el display!\n");
        pthread_exit(NULL);
    }

    // Agrego mis fuentes especiales
    ALLEGRO_FONT *fuente1 = al_load_font("../resources/Copyduck.ttf", 50, ALLEGRO_ALIGN_CENTER); // FUENTE 1
    ALLEGRO_FONT *fuente2 = al_load_font("../resources/Bing Bam Boum.ttf", 50, ALLEGRO_ALIGN_CENTER); // FUENTE 2
    ALLEGRO_FONT *fuente3 = al_load_font("../resources/Chubby Relief.ttf", 50, ALLEGRO_ALIGN_CENTER); // FUENTE 3
    ALLEGRO_FONT *fuente4 = al_load_font("../resources/Fluo Gums.ttf", 50, ALLEGRO_ALIGN_CENTER); // FUENTE 4

    if (!fuente1) { // Analizo si se crea correctamente
        fprintf(stderr, "Error al cargar la fuente1!\n");
        al_destroy_display(pantalla);
        pthread_exit(NULL);
    }

    if (!fuente2) { // Analizo si se crea correctamente
        fprintf(stderr, "Error al cargar la fuente2!\n");
        al_destroy_display(pantalla);
        pthread_exit(NULL);
    }
    if (!fuente3) { // Analizo si se crea correctamente
        fprintf(stderr, "Error al cargar la fuente3!\n");
        al_destroy_display(pantalla);
        pthread_exit(NULL);
    }
    if (!fuente4) { // Analizo si se crea correctamente
        fprintf(stderr, "Error al cargar la fuente4!\n");
        al_destroy_display(pantalla);
        pthread_exit(NULL);
    }

    al_clear_to_color(al_map_rgb(0, 0, 0)); // Limpia la pantalla con negro

    // Dibuja líneas rojas en la pantalla
    al_draw_line(0, 0, width - 1, 0, al_map_rgb(255, 0, 0), 20); // Línea superior
    al_draw_line(0, height - 1, width - 1, height - 1, al_map_rgb(255, 0, 0), 20); // Línea inferior
    al_draw_line(0, 0, 0, height - 1, al_map_rgb(255, 0, 0), 20); // Línea izquierda
    al_draw_line(width - 1, 0, width - 1, height - 1, al_map_rgb(255, 0, 0), 20); // Línea derecha
    al_draw_text(fuente1, al_map_rgb(255, 0, 0), width/2, height/2 - 300, ALLEGRO_ALIGN_CENTER, "TESTING letra 1");
    al_draw_text(fuente2, al_map_rgb(255, 0, 0), width/2, height/2 - 50, ALLEGRO_ALIGN_CENTER, "TESTING letra 2");
    al_draw_text(fuente3, al_map_rgb(255, 0, 0), width/2, height/2 + 150, ALLEGRO_ALIGN_CENTER, "TESTING letra 3");
    al_draw_text(fuente4, al_map_rgb(255, 0, 0), width/2, height/2 + 250, ALLEGRO_ALIGN_CENTER, "TESTING LETRA 4");

    al_flip_display();
    al_rest(3);

    // Destruyo la pantalla (puntero)
    al_destroy_display(pantalla);

    pthread_exit(NULL);
}
