all: app.exe

app.exe: main.o function.o
	gcc main.o function.o -o app.exe
main.o: main.c
	gcc -std=c99 -Wall -Werror -g -c main.c
function.o: function.c
	gcc -std=c99 -g -Wall -Werror -c function.c
clean:
	rm *.o app.exe
