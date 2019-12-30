all: app.exe test.exe

app.exe: main.o funcs.o
	gcc -o app.exe main.o funcs.o
test.exe: module.o funcs.o
	gcc -o test.exe module.o funcs.o -lm
main.o: main.c
	gcc -std=c99 -Wall -Werror -g -c main.c
funcs.o: funcs.c
	gcc -std=c99 -g -Wall -Werror -c funcs.c
clean:
	rm *.o app.exe test.exe
