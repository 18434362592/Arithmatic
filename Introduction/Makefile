
vpath %.c src
vpath %.h libs
CC = gcc
INCLUDE = -I libs
CFLAGS = -g -W -I libs `pkg-config --cflags gtk+-3.0`
OBJ_FILE = obj/
OBJ = $(addprefix $(OBJ_FILE),test.o sort.o permutations.o zhimi.o firework.o firework2.o)
BIN = bin

$(BIN)/test: $(OBJ) | $(BIN)
	$(CC) $(CFLAGS) -o $@ $^ -lm `pkg-config --libs gtk+-3.0`

$(OBJ_FILE)test.o: test.c sort.h

$(OBJ_FILE)sort.o: sort.c sort.h

$(OBJ_FILE)permutations.o:permutations.c permutations.h 

$(OBJ_FILE)zhimi.o:zhimi.c zhimi.h

$(OBJ_FILE)firework.o: firework.c firework.h

$(OBJ_FILE)firework2.o: firework2.c firework2.h
$(OBJ_FILE)%.o:
	$(CC) $(CFLAGS) -c $< -o $@ 

$(BIN):
	mkdir bin

.PHONY : clean
clean:
	rm $(OBJ) 
	rm -rf $(BIN)

.PHONY : test
test:
	$(BIN)/test

debug:
	gdb -tui $(BIN)/test
