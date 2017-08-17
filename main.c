#include "monty.h"
dlist_t gs;

void dlist_destroy(void)
{
	while (gs.size > 0) /* remove each element */
		dlist_remove(gs.tail);
	fclose(gs.fd);
	free(gs.buffer);
}

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
		if (glcount == -1)
			break;
		gs.buffer = buffer;
		check = run_opcode(buffer);
		free(buffer);
		buffer = NULL;
	}
	if (check < 0)/*if run_opcode fails*/
		myexit(check, buffer);
	atexit(dlist_destroy);
	return (0);
}
