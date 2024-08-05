all: testDisp testJoy testLibraries

testDisp: testDisp.c disdrv.o disdrv.h
	gcc testDisp.c disdrv.o -o testDisp -Wall

testJoy: testJoy.c joydrv.o joydrv.h
	gcc testJoy.c joydrv.o -o testJoy -Wall

testLibraries: testLibraries.c joydrv.o joydrv.h disdrv.o disdrv.h
	gcc testLibraries.c joydrv.o disdrv.o -o testLibraries -Wall
frontend: Frontend.c joydrv.o joydrv.h disdrv.o disdrv.h
	gcc Frontend.c joydrv.o disdrv.o -o Frontend -Wall