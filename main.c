#include "monty.h"

dlist_t gs;
/**
  * dlist_destroy - closes file descripter and frees buffer
  */
void dlist_destroy(void)
{
	while (gs.size > 0) /* remove each element */
		dlist_remove(gs.tail);
	if (gs.fd != NULL)
		fclose(gs.fd);
	if (gs.buffer != NULL)
		free(gs.buffer);
}
/**
  * main - monty bytecode interpreter
  * @ac: argument count
  * @av: argument variables entered from the command line
  * Return: 0 on success
  */

int main(int ac, char **av)
{
	FILE *FD;
	char *buffer = NULL;
	ssize_t glcount = 0;
	size_t bufflen = 0;

	dlist_init();
	if (ac != 2)
		myexit(-1, NULL);
	FD = fopen(av[1], "r");
	if (FD == NULL)
		myexit(-2, av[1]);
	gs.fd = FD;
	while (glcount != -1)
	{
		gs.ln++;
		glcount = getline(&buffer, &bufflen, FD);
		if (glcount == -1)
			break;
		gs.buffer = buffer;
		run_opcode(buffer);
	}
	dlist_destroy();
	return (EXIT_SUCCESS);
}
