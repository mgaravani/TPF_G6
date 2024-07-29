/*INCLUDES*/
#include <stdio.h>
#include <string.h>
#include <allegro5/allegro.h>

/*FUNCION MAIN*/
int main (void){
    char word[] = "palabra";
    int var = 250;
    printf("%d \n", var);
    printf("%d\n", (int)strlen(word));
    
    ALLEGRO_DISPLAY *pantalla; //Creo que el puntero del tipo ALLEGRO_DISPLAY

//Chequeo que allegro se inicialice correctamente
if (!al_init()) { 
  printf("Error initialising Allegro.\n");
}

pantalla = al_create_display(1000,600); //Creo la pantalla(puntero)

//Chequeo que la pantalla se inicialice correctamente
    if (!pantalla) {
  printf("Error al crear el display.\n");
    }
    
al_rest(5);

  //Destruyo la pantalla(puntero)
  al_destroy_display(pantalla);

    return 0;
}