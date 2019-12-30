all: app.exe
function.o: diman_comp_lib.c
		gcc -std=c99 -Wall -Werror -fPIC -c diman_comp_lib.c
libdiman_comp.so: diman_comp_lib.o
		gcc -shared diman_comp_lib.o -o libdiman_comp.so
app.exe: main.c libdiman_comp.so
		export LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH
		gcc -std=c99 -Wall -Werror main.c -fPIC -L. -ldiman_comp -o app.exe
clean:
		rm *.o *.exe *.so
