#include "allegro.h" //Incluyo el Header allegro

/*FUNCION init allegro*/
//Encargada de realizar todas las inicializaciones necesarias para el funcionamento
AllegroResources init_allegro() 
{
    AllegroResources resources = {.mouse_state = {0,0,false,false}}; //Creo la instancia resources del tipo de dato estructura AllegroResources

    /*CHEQUEO DE INCIALIZACIONES*/

    /*INICIALIZACION DE ALLEGRO*/
    if (!al_init()) {
        printf("Error al inicializar Allegro!\n");
        exit(EXIT_FAILURE); //Ante un fallo termina el programa y borra los recursos
    }

    /*INICIALIZACION DE SISTEMA DE ENTRADA DE TECLADO*/
    if (!al_install_keyboard()) {
        printf("No se pudo instalar el teclado.\n");
        exit(EXIT_FAILURE); //Ante un fallo termina el programa y borra los recursos
    }

    /*INICIALIZACION DE SISTEMA DE ENTRADA DEL MOUSE*/
    if (!al_install_mouse()) {
        printf("No se pudo instalar el Mouse.\n");
        exit(EXIT_FAILURE); //Ante un fallo termina el programa y borra los recursos
    }
    
    /*INICIALIZACION DEl ADDON DE FUENTES*/
    if (!al_init_font_addon()) {
        printf("Error al inicializar Allegro Fonts.\n");
        exit(EXIT_FAILURE); //Ante un fallo termina el programa y borra los recursos
    }

    /*INICIALIZACION DEl ADDON TTF PERMITIENDO TRABAJAR CON FUENTES TRUETYPE*/
    if (!al_init_ttf_addon()) {
        printf("Error al inicializar Allegro TTF.\n");
        exit(EXIT_FAILURE); //Ante un fallo termina el programa y borra los recursos
    }

    /*INICIALIZACION DEl ADDON PRIMITIVES*/
    if (!al_init_primitives_addon()) {
        printf("Error al inicializar Allegro PRIMITIVES.\n");
        exit(EXIT_FAILURE); //Ante un fallo termina el programa y borra los recursos
    }

  // Obtener el modo de pantalla completo
    ALLEGRO_DISPLAY_MODE disp_data; //Creo una variable disp_data con informacion sobre el modo de visualizacion
    /*Utilizo la funcion para obtener el modo de visualizacion, el 0 se usa para obtener el primer modo, el segundo 
    parametro es un puntero al tipo de dato ALLEGRO_DISPLAY_MODE, estructura donde se almacenara la informacion*/
    al_get_display_mode(0, &disp_data); 
    resources.width = disp_data.width; //Obtengo el ancho del modo de visualizacion y lo guardo en el campo width
    resources.height = disp_data.height; //Obtengo el alto del modo de visualizacion y lo guardo en el campo height

    // Configura el display con el flag ALLEGRO_FULLSCREEN para que la pantalla se cree en modo pantalla completa
    al_set_new_display_flags(ALLEGRO_FULLSCREEN);

    /*Creo una pantalla del modo pantalla completa, la guardo en la estructura resources en el campo pantalla*/
    resources.pantalla = al_create_display(resources.width, resources.height); 

    /*ANALIZA SI SE CREO CORRECTAMENTE*/
    if (!resources.pantalla) {
        printf("Error al crear el display!\n");
        exit(EXIT_FAILURE); //Ante un fallo termina el programa y borra los recursos
    }

    // Cargar las fuentes en la estructura resources, en el campo fuentes
    resources.fuentes[0] = al_load_font("resources/Bing Bam Boum.ttf", 200, ALLEGRO_ALIGN_CENTER); // Fuente 1
    resources.fuentes[1] = al_load_font("resources/ChineseDragon.ttf", 200, ALLEGRO_ALIGN_CENTER); // Fuente 2
    resources.fuentes[2] = al_load_font("resources/Chubby Relief.ttf", 200, ALLEGRO_ALIGN_CENTER); // Fuente 3
    resources.fuentes[3] = al_load_font("resources/Copyduck.ttf", 250, ALLEGRO_ALIGN_CENTER); // TITULO FROGGER
    resources.fuentes[4] = al_load_font("resources/Copyduck.ttf", 70, ALLEGRO_ALIGN_CENTER); // MENU INICIO
   /*fea*/ resources.fuentes[5] = al_load_font("resources/Fluo Gums.ttf", 200, ALLEGRO_ALIGN_CENTER); // Fuente 6(solo mayuscula)
    resources.fuentes[6] = al_load_font("resources/FunnyKid.ttf", 200, ALLEGRO_ALIGN_CENTER); // Fuente 7
    resources.fuentes[7] = al_load_font("resources/Smasher 312 Custom.ttf", 200, ALLEGRO_ALIGN_CENTER); // Fuente 8
    resources.fuentes[8] = al_load_font("resources/The Amazing Spider-Man.ttf", 200, ALLEGRO_ALIGN_CENTER); // Fuente 9
    resources.fuentes[9] = al_load_font("resources/The Last Comic On Earth.ttf", 200, ALLEGRO_ALIGN_CENTER); // Fuente 10

    /*ANALIZA SI LAS FUENTES SE CARGARON CORRECTAMENTE*/
    for (int i = 0; i < 10; i++) 
    {
        if (!resources.fuentes[i]) 
        {
            printf("Error al cargar la fuente %d!\n", i + 1);
            al_destroy_display(resources.pantalla); //Destruye el display
            exit(EXIT_FAILURE); //Ante un fallo termina el programa y borra los recursos
        }
    }



    return resources; //Devuelve un puntero a la estructura
}

void menu_allegro(AllegroResources resources)
{   
    // Limpia la pantalla con el color negro
    al_clear_to_color(al_map_rgb(0, 0, 0)); 

    // Dibuja el título "FROGGER" en la parte superior central de la pantalla
    al_draw_text(resources.fuentes[0], al_map_rgb(66, 194, 29), resources.width / 2, resources.height / 8,
                 ALLEGRO_ALIGN_CENTRE, "FROGGER");

    // Define las coordenadas y tamaño del botón "Play Game"
    ALLEGRO_RECTANGLE play_button = { resources.width / 2 - 200, (resources.height / 8) * 4,
                                      resources.width / 2 + 200, (resources.height / 8) * 4 + 65 };
    // Dibuja el rectángulo rojo para el botón "Play Game"
    al_draw_filled_rounded_rectangle(play_button.x1, play_button.y1, play_button.x2, play_button.y2, 10, 10, al_map_rgb(100, 0, 0));
    // Dibuja el texto "Play Game" sobre el rectángulo
    al_draw_text(resources.fuentes[4], al_map_rgb(66, 194, 29), resources.width / 2, (resources.height / 8) * 4,
                 ALLEGRO_ALIGN_CENTRE, "Play Game");

    // Define las coordenadas y tamaño del botón "High Scores"
    ALLEGRO_RECTANGLE high_scores_button = { resources.width / 2 - 220, (resources.height / 8) * 5,
                                             resources.width / 2 + 220, (resources.height / 8) * 5 + 65 };
    // Dibuja el rectángulo rojo para el botón "High Scores"
    al_draw_filled_rounded_rectangle(high_scores_button.x1, high_scores_button.y1, high_scores_button.x2, high_scores_button.y2, 10, 10, al_map_rgb(100, 0, 0));
    // Dibuja el texto "High Scores" sobre el rectángulo
    al_draw_text(resources.fuentes[4], al_map_rgb(66, 194, 29), resources.width / 2, (resources.height / 8) * 5,
                 ALLEGRO_ALIGN_CENTRE, "High Scores");

    // Define las coordenadas y tamaño del botón "Quit Game"
    ALLEGRO_RECTANGLE quit_button = { resources.width / 2 - 195, (resources.height / 8) * 6,
                                      resources.width / 2 + 195, (resources.height / 8) * 6 + 65 };
    // Dibuja el rectángulo rojo para el botón "Quit Game"
    al_draw_filled_rounded_rectangle(quit_button.x1, quit_button.y1, quit_button.x2, quit_button.y2, 10, 10, al_map_rgb(100, 0, 0));
    // Dibuja el texto "Quit Game" sobre el rectángulo
    al_draw_text(resources.fuentes[4], al_map_rgb(66, 194, 29), resources.width / 2, (resources.height / 8) * 6,
                 ALLEGRO_ALIGN_CENTRE, "Quit Game");

    al_flip_display(); //Da vuelta la pantalla para poder observar los cambios

    /*CLICK ANALISIS*/
    //Verifico si esta presionado el boton izquierdo
    if(resources.mouse_state.left_button)
    {
        //Verifica si se presiona "Play Game"
        if(((resources.mouse_state.x >= play_button.x1) && (resources.mouse_state.x <= play_button.x2))
        &&((resources.mouse_state.y >= play_button.y1) && (resources.mouse_state.y <= play_button.y2)))
        {
            inicio_partida(1,resources);
        }

        //Verifica si se presiona "High Scores"
        else if(((resources.mouse_state.x >= high_scores_button.x1) && (resources.mouse_state.x <= high_scores_button.x2))
        &&((resources.mouse_state.y >= high_scores_button.y1) && (resources.mouse_state.y <= high_scores_button.y2)))
        {
            inicio_partida(2,resources);
        }

        //Verifica si se presiona "Quit Game"
        else if(((resources.mouse_state.x >= quit_button.x1) && (resources.mouse_state.x <= quit_button.x2))
        &&((resources.mouse_state.y >= quit_button.y1) && (resources.mouse_state.y <= quit_button.y2)))
        {
            inicio_partida(3,resources);
        }
    }

    // Limpia el estado del mouse después de procesar el evento
    resources.mouse_state.left_button = false;
}

/*FUNCION inicio_partida*/
//TESTEO POR EL MOMENTO
void inicio_partida(int opcion, AllegroResources resources)
{
    switch (opcion)
    {
    case 1:
    // Limpia la pantalla con el color negro
    al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_text(resources.fuentes[4], al_map_rgb(66, 194, 29), resources.width / 2, (resources.height / 8) * 4,
                 ALLEGRO_ALIGN_CENTRE, "Play Game"); 
        al_flip_display();
        al_rest(4);
        break;

    case 2:
    // Limpia la pantalla con el color negro
    al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_text(resources.fuentes[4], al_map_rgb(66, 194, 29), resources.width / 2, (resources.height / 8) * 4,
                 ALLEGRO_ALIGN_CENTRE, "High Scores"); 
        al_flip_display();
        al_rest(4);
        break;

    case 3:
            // Salir del programa
            exit(EXIT_SUCCESS);
        break;
    }

}

/*FUNCION cleanup_allegro*/
//Borra todos los recursos utilizados
void cleanup_allegro(AllegroResources resources) 
{
    for (int i = 0; i < 10; i++) 
    {
        if (resources.fuentes[i]) 
        {
            al_destroy_font(resources.fuentes[i]);
        }
    }
    if (resources.pantalla) 
    {
        al_destroy_display(resources.pantalla);
    }
}
