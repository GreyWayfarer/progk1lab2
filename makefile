all:main
main: build/main.o build/IntVector.o
	gcc -Wall -Werror build/main.o build/IntVector.o -o main

build/main.o: src/main2.c
	gcc -Wall -Werror -c src/main2.c -o build/main.o

build/IntVector.o: src/IntVector.c
	gcc -Wall -Werror -c src/IntVector.c -o build/IntVector.o
