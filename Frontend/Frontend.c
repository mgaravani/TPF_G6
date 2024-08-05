#include <stdio.h>
#include "disdrv.h"
#include "joydrv.h"
#define THRESHOLD 120

int main()
{
    joy_init();										//inicializa el joystick
	disp_init();									//inicializa el display
	disp_clear();									//limpia todo el display
    void disp_write(dcoord_t coord, dlevel_t val);
    dcoord_t pos = {DISP_MAX_X>>1 , 0 };	//pos es la posición actual, empieza en el centro de la parte inferior
	dcoord_t npos = pos;
    joyinfo_t coord = {0,0,J_NOPRESS};
    char cambio = 0;
    do
    {
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
    } while (coord.sw == J_NOPRESS);
    disp_clear();
    disp_update();


    return 0;
}