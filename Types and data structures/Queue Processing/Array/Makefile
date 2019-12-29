all: app.exe

app.exe: main.o function.o
	gcc main.o function.o system.o request.o -o app.exe
main.o: main.c system.o request.o
	gcc -std=c99 -Wall -Werror -g -c main.c
function.o: function.c
	gcc -std=c99 -g -Wall -Werror -c function.c
request.o: request.c
	gcc -std=c99 -g -Wall -Werror -c request.c
system.o: system.c
	gcc -std=c99 -g -Wall -Werror -c system.c
clean:
	rm *.o app.exe
