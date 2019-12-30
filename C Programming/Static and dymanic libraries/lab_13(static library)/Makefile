all: app.exe

app.exe: main.o
	gcc -o app.exe main.o libfunc.a -lm
main.o: main.c
	gcc -std=c99 -Wall -Werror -g3 -c -lm main.c
clean:
	rm *.o app.exe
