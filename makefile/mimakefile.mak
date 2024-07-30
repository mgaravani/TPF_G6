# Variables
CC := gcc
OPTIONS := -O2 -g -Wall
ALLEGRO := -lallegro -lallegro_main -lallegro_image -lallegro_font -lallegro_ttf -lallegro_primitives -lallegro_audio -lallegro_acodec
SRC_DIR := Backend
OBJ_DIR := objetos
SOURCES := $(SRC_DIR)/main.c $(SRC_DIR)/allegro.c
OBJECTS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SOURCES))

# Target principal
main: $(OBJECTS)
	$(CC) $(OPTIONS) $(OBJECTS) $(ALLEGRO) -o main

# Regla para archivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(OPTIONS) -c $< -o $@ -I/usr/local/include

# Borra todos los objetos y el ejecutable
clean:
	rm -rf $(OBJ_DIR) main

.PHONY: clean
