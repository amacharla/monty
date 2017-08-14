#var
FLAGS = -Wall -Werror -Wextra -pedantic -g

#Build
all: main

main:
	gcc $(FLAGS)

test:
	gcc -g
r: main
	./a.out
t: test
	gdb ./a.out
