#ifndef ALLEGRO_H
#define ALLEGRO_H

#include <pthread.h>
#include <allegro5/allegro_font.h> // Incluyo el addon font
typedef struct {
    ALLEGRO_DISPLAY *display;
    ALLEGRO_FONT *fuentes[4]; // Array para las fuentes
} AllegroResources;

AllegroResources init_allegro();
void draw_text(AllegroResources resources, int font_index, const char *text, float x, float y);
void cleanup_allegro(AllegroResources resources);

#endif /* ALLEGRO_H */
