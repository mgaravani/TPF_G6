#ifndef RANITA
#define RANITA

#define ALTO 8
#define ANCHO 8
typedef struct {
    int X;
    int Y;
}ranita_t;
ranita_t* mov_rana(ALLEGRO_EVENT event, ranita_t *rana);

#endif