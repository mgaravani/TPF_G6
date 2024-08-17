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
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    //Registra eventos relacionados con el display
    al_register_event_source(event_queue, al_get_display_event_source(pantalla));

    return event_queue;
}

/*FUNCION manejo_eventos*/
//Utilizada para el manejo de los eventos
void manejo_eventos(AllegroResources *resources, ALLEGRO_EVENT_QUEUE *event_queue)
{   
    ALLEGRO_EVENT evento_teclado; //Variable para almacenar el evento
    al_get_next_event(event_queue, &evento_teclado);

  
    // Manejo de teclado
    if (evento_teclado.type == ALLEGRO_EVENT_KEY_DOWN) {
        switch (evento_teclado.keyboard.keycode) {
            case ALLEGRO_KEY_DOWN:
                if (resources->selected_option < 3) resources->selected_option++;
                break;
            case ALLEGRO_KEY_UP:
                if (resources->selected_option > 1) resources->selected_option--;
                break;
            case ALLEGRO_KEY_ENTER:
                // Maneja la selección de la opción
                if(resources->selected_option == 1) //Si se eligio Play game
                {
                    inicio_partida(*resources);
                }
                else if(resources->selected_option == 2) //Si se eligio High Scores
                {
                    // Código para High Scores
                }
                else
                {
                    exit(EXIT_SUCCESS);//Si se eligio Quit Game
                }
                break;
            case ALLEGRO_KEY_ESCAPE:
                // Salir del programa
                cleanup_allegro(*resources);
                exit(EXIT_SUCCESS);
                break;
        }
    
    }

    /*CIERRE DE PANTALLA*/
    //Verifica si se cierra la pantalla, entonces destruye la cola de eventos
    if (evento_teclado.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        al_destroy_event_queue(event_queue);
        cleanup_allegro(*resources);
        exit(EXIT_SUCCESS);
    }
}


 
