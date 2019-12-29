all: app.exe

app.exe: main.o hash.o
	gcc main.o hash.o system.o tree.o -o app.exe
main.o: main.c system.o tree.o
	gcc -std=c99 -g -c main.c
hash.o: hash.c
	gcc -std=c99 -g -Wall -Werror -c hash.c
tree.o: tree.c
	gcc -std=c99 -g -Wall -Werror -c tree.c
system.o: system.c
	gcc -std=c99 -g -Wall -Werror -c system.c
clean:
	rm *.o app.exe
