all: app.exe

app.exe: main.o function.o
	gcc main.o function.o libui.a `pkg-config --cflags --libs gtk+-3.0` -ldl  -o app.exe
main.o: main.c
	gcc -std=c99 -Wall -Werror -g -c -lm main.c
function.o: function.c
	gcc -std=c99 -g -Wall -Werror -c -lm function.c
clean:
	rm *.o app.exe
