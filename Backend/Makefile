# Regla principal para compilar el ejecutable final 'main' a partir de los archivos objeto 'allegro.o' y 'main.o'
main: allegro.o main.o
	# Enlaza los archivos objeto y genera el ejecutable 'main', enlazando las bibliotecas necesarias
	gcc allegro.o main.o -g -o main -Wall -lallegro -lallegro_primitives -lallegro_font -lallegro_ttf -lpthread

# Regla para compilar 'allegro.c' en el archivo objeto 'allegro.o'
allegro.o: allegro.c allegro.h
	# Compila 'allegro.c' con advertencias habilitadas
	gcc allegro.c -c -Wall

# Regla para compilar 'main.c' en el archivo objeto 'main.o'
main.o: main.c
	# Compila 'main.c' con advertencias habilitadas
	gcc main.c -c -Wall

# Regla de limpieza para eliminar los archivos objeto y el ejecutable
clean:
	# Elimina los archivos objeto y el ejecutable
	rm -f *.o main
