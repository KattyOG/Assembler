all: app.exe

app.exe: main.o graph.o
	gcc main.o graph.o -o app.exe
main.o: main.c
	gcc -std=c99 -g -c main.c
graph.o: graph.c
	gcc -std=c99 -g -Wall -Werror -c graph.c
clean:
	rm *.o app.exe
