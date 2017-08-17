#include "monty.h"
extern dlist_t gs;
int main(int ac, char **av)
{
	FILE FD;
	char *buffer = NULL;
	int check = 0;
	size_t glcount = 0;
	ssize_t bufflen = 0;

	dlist_init();
	if (ac != 2)
		myexit(-1, NULL);
	FD = fopen(av[1], r);
	if (FD == NULL)
		myexit(-2, av[1]);
	while (glcount != -1 && check >= 0)
	{
		gs.ln++;
		glcount = getline(&buffer, &bufferlen, FD);
		check = run_opcode(buffer);
	}
	if (glcount == -1 && check == 0)/*if getline fails*/
		myexit(-3, buffer);
	if (check < 0)/*if run_opcode fails*/
		myexit(check, buf);
	exit(EXIT_SUCCESS);
	on_exit(dlist_destroy());
	on_exit(free(buffer)), on_exit(close(FD));
}
