#include "monty.h"

extern dlist_t gs;

int main(int ac, char **av)
{
	FILE *FD;
	char *buffer = NULL;
	int check = 0;
	ssize_t glcount = 0;
	size_t bufflen = 0;

	dlist_init();
	if (ac != 2)
		myexit(-1, NULL);
	FD = fopen(av[1], "r");
	if (FD == NULL)
		myexit(-2, av[1]);
	gs.fd = FD;
	while (glcount != -1 && check >= 0)
	{
		gs.ln++;
		glcount = getline(&buffer, &bufflen, FD);
		gs.buffer = buffer;
		check = run_opcode(buffer);
	}
	if (glcount == -1 && check == 0)/*if getline fails*/
		myexit(-3, buffer);
	if (check < 0)/*if run_opcode fails*/
		myexit(check, buffer);
	exit(EXIT_SUCCESS);
	atexit(dlist_destroy);
}
