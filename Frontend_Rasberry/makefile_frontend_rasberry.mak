
frontend: Frontend.c joydrv.o joydrv.h disdrv.o disdrv.h
	gcc Frontend.c joydrv.o disdrv.o -o Frontend -Wall