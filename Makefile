SRC = ./src
INC = ./include
OBJ = ./obj
APP = ./apps
BIN = ./bin

ALL: buildSrcs buildApps

buildSrcs:
	gcc -c $(SRC)/manager.c -I $(INC)/ -o $(OBJ)/manager.o
	gcc -c $(SRC)/list.c -I $(INC)/ -o $(OBJ)/list.o
	gcc -c $(SRC)/stack.c -I $(INC)/ -o $(OBJ)/stack.o

buildApps:
	gcc $(APP)/app.c $(OBJ)/* -I $(INC)/ -o $(BIN)/app
	gcc $(APP)/app_stack.c $(OBJ)/* -I $(INC)/ -o $(BIN)/app_stack

run:
	$(BIN)/app

runAppStack:
	$(BIN)/app_stack

clean:
	rm -f $(BIN)/* $(OBJ)/*