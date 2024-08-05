#include <stdio.h>
#include "disdrv.h"
#include "joydrv.h"
#define THRESHOLD 100

int main()
{
    joy_init();										//inicializa el joystick
	disp_init();									//inicializa el display
	disp_clear();									//limpia todo el display
    void disp_write(dcoord_t coord, dlevel_t val);
    dcoord_t pos = {DISP_MAX_X>>1 , 0 };	//pos es la posición actual, empieza en el centro de la parte inferior
	dcoord_t npos = pos;
    joyinfo_t coord = {0,0,J_NOPRESS};

    do
    {
        printf("Joystick: (%4d,%4d)" , coord.x, coord.y);	//Imprime las coordenadas del joystick
		printf(" | ");
		printf("Display: (%2d,%2d)\n" , npos.x, npos.y);	//Imprime la posición del LED encendio

        disp_update();	//Actualiza el display con el contenido del buffer
		coord = joy_read();	//Guarda las coordenadas medidas

        if(coord.x > THRESHOLD && npos.x < DISP_MAX_X)
		{
			npos.x++;
		}
		if(coord.x < -THRESHOLD && npos.x > DISP_MIN)
		{
			npos.x--;
		}
		if(coord.y > THRESHOLD && npos.y > DISP_MIN)
		{
			npos.y--;
		}
		if(coord.y < -THRESHOLD && npos.y < DISP_MAX_Y)
		{
			npos.y++;
		}
        
		disp_write(pos,D_OFF);	//apaga la posición vieja en el buffer
		disp_write(npos,D_ON);	//enciende la posición nueva en el buffer
		pos = npos;				//actualiza la posición actual
        usleep(100);//tiempo de espera para que no sea muy rapido el movimiento
    } while (coord.sw == J_NOPRESS);
    disp_clear();
    disp_update();


    return 0;
}