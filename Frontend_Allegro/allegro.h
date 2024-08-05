#ifndef ALLEGRO_H
#define ALLEGRO_H

/*INCLUDES*/
#include <stdio.h>  // Incluyo la librería estándar stdio
#include <pthread.h> //Incluyo la libreria de threads
#include <allegro5/allegro.h> // Incluyo la librería Allegro
#include <allegro5/allegro_primitives.h> // Incluyo el addon primitives
#include <allegro5/allegro_ttf.h>  // Incluye el addon para fuentes TTF
#include <allegro5/allegro_font.h> // Incluyo el addon font
#include <allegro5/allegro_color.h> //Incluyo el addon color

/*PASAR LOS INT A UINT_32T*/
/*ESTRUCTURAS*/

//Definicion de estructura para guardar coordenadas de rectangulos
typedef struct {
    int x1, y1; // Coordenadas de la esquina superior izquierda
    int x2, y2; // Coordenadas de la esquina inferior derecha
} ALLEGRO_RECTANGLE;

// Definición de la estructura para almacenar el estado del mouse
typedef struct {
    int x;              // Posición x del mouse
    int y;              // Posición y del mouse
    bool left_button;   // Estado del botón izquierdo del mouse
    bool right_button;  // Estado del botón derecho del mouse
} MouseState;

/*Creo un tipo de dato de estructura llamado AllegroResources 
donde se guardan las fuentes, puntero a display y otros recursos*/
typedef struct 
{
    ALLEGRO_DISPLAY *pantalla; //Puntero al tipo de dato ALLEGRO_DISPLAY para la pantalla
    ALLEGRO_FONT *fuentes[10]; // Array de punteros al tipo ALLEGRO_FONT para las fuentes a utilizar 
    int width;
    int height;
    MouseState mouse_state;
} AllegroResources;

/*PROTOTYPES*/

/*FUNCION init_allegro*/
//Recibira dos punteros a matrices y algo mas....COMPLETAR CUANDO SE DISEÑE
AllegroResources init_allegro(); //Encargada de realizar todas las inicializaciones necesarias para el funcionamento

/*FUNCION menu_allegro*/
//Da inicio al juego mostrando un menu de inicio para seleccionar el modo de juego y dar comienzo a la partida
//Recibe la estructura resources
void menu_allegro(AllegroResources resources);

/*FUNCION cleanup_allegro*/
//Borra todos los recursos utilizados
void cleanup_allegro(AllegroResources resources);

/*FUNCION events*/
//Creacion de eventos
ALLEGRO_EVENT_QUEUE *init_events(ALLEGRO_DISPLAY *pantalla);

/*FUNCION manejo_eventos*/
//Utilizada para el manejo de los eventos
void manejo_eventos(AllegroResources *resources, ALLEGRO_EVENT_QUEUE * event_queue);

/*FUNCION inicio_partida*/
//TESTEO POR AHORA
void inicio_partida(int opcion, AllegroResources resources);

#endif /* ALLEGRO_H */