#var
FLAGS = -Wall -Werror -Wextra -pedantic -g

#Build
all: main

main:
	gcc $(FLAGS) main.c functions.c mathfunc.c run_opcode.c functions3.c dlist.c
#Test
0: main
	./a.out bytecodes/0.m
1: main
	./a.out bytecodes/pint.m
2: main
	./a.out bytecodes/pop.m
3: main
	./a.out bytecodes/swap.m
4: main
	./a.out bytecodes/add.m
6: main
	./a.out bytecodes/sub.m
7: main
	./a.out bytecodes/div.m
7: main
	./a.out bytecodes/mul.m
7: main
	./a.out bytecodes/mod.m
#Debug
t: main
	gdb ./a.out
v: main
	valgrind ./a.out bytecodes/0.m
