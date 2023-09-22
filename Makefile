

ALL: buildSrcs buildApps

buildSrcs:
	gcc -c ./src/manager.c -I ./include/ -o ./obj/manager.o
	gcc -c ./src/list_handler.c -I ./include/ -o ./obj/list_handler.o
	gcc -c ./src/stack.c -I ./include/ -o ./obj/stack.o

buildApps:
	gcc ./apps/app.c ./obj/* -I ./include/ -o ./bin/app

run:
	./bin/app

clean:
	rm -f ./bin/* ./obj/*