
vpath %.c src
vpath %.h libs
CC = gcc
INCLUDE = -I libs
CFLAGS = -g -W -I libs
OBJ_FILE = obj/
OBJ = $(addprefix $(OBJ_FILE),test.o sort.o permutations.o zhimi.o)
BIN = bin

$(BIN)/test: $(OBJ) | $(BIN)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_FILE)test.o: test.c sort.h

$(OBJ_FILE)sort.o: sort.c sort.h

$(OBJ_FILE)permutations.o:permutations.c permutations.h 

$(OBJ_FILE)zhimi.o:zhimi.c zhimi.h

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
