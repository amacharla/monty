#var
FLAGS = -Wall -Werror -Wextra -pedantic -g

#Build
all: main

main:
	gcc $(FLAGS) main.c functions.c run_opcode.c dlist.c

test:
	gcc -g
r: main
	./a.out bytecode.m
t: test
	gdb ./a.out
v: main
	valgrind ./a.out bytecode.m
