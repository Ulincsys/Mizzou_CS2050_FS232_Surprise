library:
	gcc -c -Wall -Werror -Wpedantic -fpic --std=c11 -o mylib.o mylib.c
	gcc -shared -o libs/libmylib.so mylib.o

main-static:
	gcc -Wall -Werror -Wpedantic --std=c11 main.c mylib.c

main-shared: library
	gcc -Wall -Werror -Wpedantic --std=c11 -L libs/ main.c -lmylib

main-dynamic: library
	gcc -Wall -Werror --std=c11 dyn_main.c