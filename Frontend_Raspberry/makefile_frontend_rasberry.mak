all: frontend Converter

frontend: Frontend.c joydrv.o joydrv.h disdrv.o disdrv.h
	gcc Frontend.c joydrv.o disdrv.o -o Frontend -Wall
Converter: Converter.c joydrv.o joydrv.h disdrv.o disdrv.h
	gcc Converter.c joydrv.o disdrv.o -o Converter -Wall