#ifndef ALLEGRO_H
#define ALLEGRO_H

/*INCLUDES*/
#include <pthread.h> //Incluyo la libreria de threads
#include <allegro5/allegro.h> // Incluyo la librería Allegro
#include <allegro5/allegro_primitives.h> // Incluyo el addon primitives
#include <allegro5/allegro_ttf.h>  // Incluye el addon para fuentes TTF
#include <allegro5/allegro_font.h> // Incluyo el addon font
#include <allegro5/allegro_color.h> //Incluyo el addon color

/*ESTRUCTURAS*/

/*Creo un tipo de dato de estructura llamado AllegroResources 
donde se guardan las fuentes, puntero a display y otros recursos*/
typedef struct 
{
    ALLEGRO_DISPLAY *pantalla; //Puntero al tipo de dato ALLEGRO_DISPLAY para la pantalla
    ALLEGRO_FONT *fuentes[10]; // Array de punteros al tipo ALLEGRO_FONT para las fuentes a utilizar 
} AllegroResources;

/*PROTOTYPES*/

/*FUNCION init_allegro*/
//Recibira dos punteros a matrices y algo mas....COMPLETAR CUANDO SE DISEÑE
AllegroResources init_allegro(); //Encargada de realizar todas las inicializaciones necesarias para el funcionamento

/*FUNCION menu_allegro*/
//Da inicio al juego mostrando un menu de inicio para seleccionar el modo de juego y dar comienzo a la partida
void menu_allegro(AllegroResources resources, int width,  int height);

#endif /* ALLEGRO_H */
