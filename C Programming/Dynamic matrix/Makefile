all: app.exe test.exe

app.exe: main.o function.o
	gcc -o app.exe main.o function.o -lm
test.exe: module.o function.o
	gcc -o test.exe module.o function.o -lm
main.o: main.c
	gcc -std=c99 -Wall -Werror -g -c -lm main.c

function.o: function.c
	gcc -std=c99 -g -Wall -Werror -c -lm function.c
module.o: module.c
	gcc -std=c99 -g -Wall -Werror -c -lm module.c
clean:
	rm *.o app.exe test.exe
