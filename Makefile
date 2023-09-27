SRC = ./src
INC = ./include
OBJ = ./obj
APP = ./apps
BIN = ./bin

ALL: srcs apps

srcs: \
	$(OBJ)/manager.o \
	$(OBJ)/list.o \
	$(OBJ)/stack.o \
	$(OBJ)/queue.o

apps: \
	$(BIN)/app \
	$(BIN)/app_stack

$(OBJ)/%.o: $(SRC)/%.c
	gcc -c $< -I $(INC)/ -o $@

$(BIN)/%: $(APP)/%.c
	gcc $< $(OBJ)/* -I $(INC)/ -o $@

run:
	$(BIN)/app

runAppStack:
	$(BIN)/app_stack

clean:
	rm -f $(BIN)/* $(OBJ)/*