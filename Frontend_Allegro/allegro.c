#include <stdio.h>  // Incluyo la librería estándar stdio
#include "allegro.h" //Incluyo el Header allegro

/*FUNCION init allegro*/
//Encargada de realizar todas las inicializaciones necesarias para el funcionamento
AllegroResources init_allegro() 
{
    AllegroResources resources; //Creo la instancia resources del tipo de dato estructura AllegroResources

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
    int width = disp_data.width; //Obtengo el ancho del modo de visualizacion y lo guardo en la variable width
    int height = disp_data.height; //Obtengo el alto del modo de visualizacion y lo guardo en la variable height

    // Configura el display con el flag ALLEGRO_FULLSCREEN para que la pantalla se cree en modo pantalla completa
    al_set_new_display_flags(ALLEGRO_FULLSCREEN);

    /*Creo una pantalla del modo pantalla completa, la guardo en la estructura resources en el campo pantalla*/
    resources.pantalla = al_create_display(width, height); 

    /*ANALIZA SI SE CREO CORRECTAMENTE*/
    if (!resources.pantalla) {
        printf("Error al crear el display!\n");
        exit(EXIT_FAILURE); //Ante un fallo termina el programa y borra los recursos
    }

    // Cargar las fuentes en la estructura resources, en el campo fuentes
    resources.fuentes[0] = al_load_font("resources/Bing Bam Boum.ttf", 36, ALLEGRO_ALIGN_CENTER); // Fuente 1
    resources.fuentes[1] = al_load_font("resources/ChineseDragon.ttf", 36, ALLEGRO_ALIGN_CENTER); // Fuente 2
    resources.fuentes[2] = al_load_font("resources/Chubby Relief.ttf", 36, ALLEGRO_ALIGN_CENTER); // Fuente 3
    resources.fuentes[3] = al_load_font("resources/Copyduck.ttf", 36, ALLEGRO_ALIGN_CENTER); // Fuente 4
    resources.fuentes[4] = al_load_font("resources/DOCALLISME ON STREET.ttf", 36, ALLEGRO_ALIGN_CENTER); // Fuente 5
    resources.fuentes[5] = al_load_font("resources/Fluo Gums.ttf", 36, ALLEGRO_ALIGN_CENTER); // Fuente 6(solo mayuscula)
    resources.fuentes[6] = al_load_font("resources/FunnyKid.ttf", 36, ALLEGRO_ALIGN_CENTER); // Fuente 7
    resources.fuentes[7] = al_load_font("resources/Smasher 312 Custom.ttf", 36, ALLEGRO_ALIGN_CENTER); // Fuente 8
    resources.fuentes[8] = al_load_font("resources/The amazing Spider-Man.ttf", 36, ALLEGRO_ALIGN_CENTER); // Fuente 9
    resources.fuentes[9] = al_load_font("resources/The Last Comic On Earth.ttf", 36, ALLEGRO_ALIGN_CENTER); // Fuente 10

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

void menu_allegro(AllegroResources resources, int width,  int height)
{
    al_clear_to_color(al_map_rgb(0, 0, 0)); // Limpia la pantalla con negro
    
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
    if (resources.pantalla) {
        al_destroy_display(resources.pantalla);
    }
}