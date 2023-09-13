

ALL: buildSrcs buildApps

buildSrcs:
	gcc -c ./src/manager.c -I ./include/ -o ./obj/manager.o

buildApps:
	gcc ./apps/app.c ./obj/manager.o -I ./include/ -o ./bin/app

run:
	./bin/app

clean:
	rm -f ./bin/* ./obj/*