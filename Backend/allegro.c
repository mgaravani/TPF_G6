#include <stdio.h>  // Incluyo la librería estándar stdio
#include "allegro.h"
#include <allegro5/allegro.h> // Incluyo la librería Allegro
#include <allegro5/allegro_primitives.h> // Incluyo el addon primitives
#include <allegro5/allegro_ttf.h>  // Incluye el addon para fuentes TTF


AllegroResources init_allegro() {
    AllegroResources resources;

    if (!al_init()) {
        printf("Error al inicializar Allegro!\n");
        exit(EXIT_FAILURE);
    }

    if (!al_install_keyboard()) {
        printf("No se pudo instalar el teclado.\n");
        exit(EXIT_FAILURE);
    }

    if (!al_init_font_addon()) {
        printf("Error al inicializar Allegro Fonts.\n");
        exit(EXIT_FAILURE);
    }

    if (!al_init_ttf_addon()) {
        printf("Error al inicializar Allegro TTF.\n");
        exit(EXIT_FAILURE);
    }

  // Obtener el modo de pantalla completo
    ALLEGRO_DISPLAY_MODE disp_data;
    al_get_display_mode(0, &disp_data);
    int width = disp_data.width;
    int height = disp_data.height;

    // Configura el display para pantalla completa
    al_set_new_display_flags(ALLEGRO_FULLSCREEN);

    resources.display = al_create_display(width, height); // Usa la resolución de pantalla completa
    if (!resources.display) {
        printf("Error al crear el display!\n");
        exit(EXIT_FAILURE);
    }

    // Cargar las fuentes en el array
    resources.fuentes[0] = al_load_font("../resources/Bing Bam Boum.ttf", 36, ALLEGRO_ALIGN_CENTER); // Fuente 1
    resources.fuentes[1] = al_load_font("../resources/Chubby Relief.ttf", 36, ALLEGRO_ALIGN_CENTER); // Fuente 2
    resources.fuentes[2] = al_load_font("../resources/Copyduck.ttf", 36, ALLEGRO_ALIGN_CENTER); // Fuente 3
    resources.fuentes[3] = al_load_font("../resources/Fluo Gums.ttf", 36, ALLEGRO_ALIGN_CENTER); // Fuente 4

    for (int i = 0; i < 4; i++) {
        if (!resources.fuentes[i]) {
            printf("Error al cargar la fuente %d!\n", i + 1);
            al_destroy_display(resources.display);
            exit(EXIT_FAILURE);
        }
    }

    return resources;
}

void draw_text(AllegroResources resources, int font_index, const char *text, float x, float y) {
    if (font_index < 0 || font_index >= 4) {
        printf("Índice de fuente inválido!\n");
        return;
    }

    al_clear_to_color(al_map_rgb(0, 0, 0)); // Limpia la pantalla con negro
    al_draw_text(resources.fuentes[font_index], al_map_rgb(255, 0, 0), x, y, ALLEGRO_ALIGN_CENTER, text);
    al_flip_display();
}

void cleanup_allegro(AllegroResources resources) {
    for (int i = 0; i < 4; i++) {
        if (resources.fuentes[i]) {
            al_destroy_font(resources.fuentes[i]);
        }
    }
    if (resources.display) {
        al_destroy_display(resources.display);
    }
}
