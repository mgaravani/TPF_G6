#include <allegro5/allegro.h>
#include <allegro5/allegro_keycodes.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>

ranita_t* mov_rana(ALLEGRO_EVENT event, ranita_t *rana) {
    if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
        switch (event.keyboard.keycode) {
            case ALLEGRO_KEY_W:
                printf("W key pressed\n");
                if (rana->Y < ALTO) {
                    rana->Y = rana->Y + 1;
                }
                break;
            case ALLEGRO_KEY_A:
                printf("A key pressed\n");
                if (rana->X > 0) {
                    rana->X = rana->X - 1;
                }
                break;
            case ALLEGRO_KEY_S:
                printf("S key pressed\n");
                if (rana->Y > 0) {
                    rana->Y = rana->Y - 1;
                }
                break;
            case ALLEGRO_KEY_D:
                printf("D key pressed\n");
                if (rana->X < ANCHO) {
                    rana->X = rana->X + 1;
                }
                break;
            case ALLEGRO_KEY_UP:
                printf("Up arrow key pressed\n");
                if (rana->Y < ALTO) {
                    rana->Y = rana->Y + 1;
                }
                break;
            case ALLEGRO_KEY_DOWN:
                printf("Down arrow key pressed\n");
                if (rana->Y > 0) {
                    rana->Y = rana->Y - 1;
                }
                break;
            case ALLEGRO_KEY_LEFT:
                printf("Left arrow key pressed\n");
                if (rana->X > 0) {
                    rana->X = rana->X - 1;
                }
                break;
            case ALLEGRO_KEY_RIGHT:
                printf("Right arrow key pressed\n");
                if (rana->X < ANCHO) {
                    rana->X = rana->X + 1;
                }
                break;
        }
    }
    return rana;
}