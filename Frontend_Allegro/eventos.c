#include "allegro.h"

ALLEGRO_EVENT_QUEUE *init_events(ALLEGRO_DISPLAY *pantalla)
{
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue(); //Crea una cola de eventos

    /*ANALIZA SI SE PUDO CREAR*/
    if (!event_queue) 
    {
        fprintf(stderr, "No se pudo crear la cola de eventos.\n");
        exit(EXIT_FAILURE); //Ante un fallo termina el programa y borra los recursos
    }

    //Registra una fuente de eventos del mouse en la cola especificada
    al_register_event_source(event_queue, al_get_mouse_event_source());
    //Registra eventos relacionados con el display
    al_register_event_source(event_queue, al_get_display_event_source(pantalla));

    return event_queue;
}

/*FUNCION manejo_eventos*/
//Utilizada para el manejo de los eventos
void manejo_eventos(AllegroResources *resources, ALLEGRO_EVENT_QUEUE * event_queue)
{
    ALLEGRO_EVENT evento_mouse; //Variable para almacenar el evento
    al_get_next_event(event_queue, &evento_mouse);//Obtiene el siguiente evento de la cola y lo almacena en evento_mouse

    /*MOVIMIENTO DEL MOUSE*/
    //Verifica si el mouse se mueve y guarda las coordenadas
    if (evento_mouse.type == ALLEGRO_EVENT_MOUSE_AXES) 
    {
        resources->mouse_state.x = evento_mouse.mouse.x;
        resources->mouse_state.y = evento_mouse.mouse.y;
    }

    /*BOTON DEL MOUSE PRESIONADO*/
    //Verifica si se presiona un boton del mouse
    if (evento_mouse.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) 
    {
        if (evento_mouse.mouse.button & 1) //Comprueba si es el boton izquierdo
        {
            resources->mouse_state.left_button = true;
        }
        if (evento_mouse.mouse.button & 2) //Comprueba si es el boton derecho
        {
            resources->mouse_state.right_button = true;
        }
    }

    /*BOTON DEL MOUSE SIN PRESIONAR*/
    //Verifica si se deja de presionar
    if (evento_mouse.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) 
    {
        if (evento_mouse.mouse.button & 1) {
            resources->mouse_state.left_button = false; //Comprueba si es el boton izquierdo
        }
        if (evento_mouse.mouse.button & 2) {
            resources->mouse_state.right_button = false; //Comprueba si es el boton derecho
        }
    }

    /*CIERRE DE PANTALLA*/
    //Verifica si se cierra la pantalla, entonces destruye la cola de eventos
    if (evento_mouse.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        al_destroy_event_queue(event_queue);
        cleanup_allegro(*resources);
        exit(EXIT_SUCCESS);
    }

}