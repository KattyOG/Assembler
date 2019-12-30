all: app.exe
dinam_load.o: dinam_load.c
		gcc -std=c99 -Wall -Werror -fPIC -c dinam_load.c
dinam_load.so: dinam_load.o
		gcc -shared dinam_load.o -o dinam_load.so
app.exe: main.c dinam_load.so
		export LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH
		gcc -std=c99 -Wall -Werror main.c -o app.exe -ldl
clean:
		rm *.o *.exe *.so
