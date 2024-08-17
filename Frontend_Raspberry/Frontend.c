#include <stdio.h>
#include <unistd.h>
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
			usleep(1000);
			npos.x++;
		}
		if(coord.x < -THRESHOLD && npos.x > DISP_MIN)
		{
			usleep(1000);
			npos.x--;
		}
		if(coord.y > THRESHOLD && npos.y > DISP_MIN)
		{
			usleep(1000);
			npos.y--;
		}
		if(coord.y < -THRESHOLD && npos.y < DISP_MAX_Y)
		{
			npos.y++;
			usleep(1000);
		}
        
		disp_write(pos,D_OFF);	//apaga la posición vieja en el buffer
		disp_write(npos,D_ON);	//enciende la posición nueva en el buffer
		pos = npos;				//actualiza la posición actual
        
    } while (coord.sw == J_NOPRESS);
    disp_clear();
    disp_update();
	dcoord_t myPoint;
			myPoint.x=6;
			myPoint.y=6;
			disp_write(myPoint, D_ON);				//prende el LED en el buffer. Otra opción es: disp_write({i, j}, D_ON);
			printf("(%2d,%2d) " , myPoint.x, myPoint.y);//imprime cuál LED fue encendido
			disp_update();							//ahora lo vemos en el display
            sleep(1);
			disp_write(myPoint, D_OFF);				//prende el LED en el buffer. Otra opción es: disp_write({i, j}, D_ON);
			printf("(%2d,%2d) " , myPoint.x, myPoint.y);//imprime cuál LED fue encendido
			disp_update();							//ahora lo vemos en el display
            sleep(1);
			disp_write(myPoint, D_ON);				//prende el LED en el buffer. Otra opción es: disp_write({i, j}, D_ON);
			printf("(%2d,%2d) " , myPoint.x, myPoint.y);//imprime cuál LED fue encendido
			disp_update();							//ahora lo vemos en el display
            sleep(1);
			disp_write(myPoint, D_OFF);				//prende el LED en el buffer. Otra opción es: disp_write({i, j}, D_ON);
			printf("(%2d,%2d) " , myPoint.x, myPoint.y);//imprime cuál LED fue encendido
			disp_update();							//ahora lo vemos en el display
                
	sleep(2);   //wait 2 seconds
    printf("Clearing Display!\n");

    disp_clear();
    disp_update();

    return 0;
}