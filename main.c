#include "monty.h"

int main(int ac, char **av)
{
	FILE FP;
	char *buffer = NULL;
	int check = 0;
	unsigned int linecount = 0;
	size_t glcount = 0;
	ssize_t bufflen = 0;

	if (ac != 2)
		myexit(-1);
	FP = fopen(av[1], r);
	if (FP == NULL)
		myexit(-2);
	while (glcount != -1 && check >= 0)
	{
		linecount++;
		glcount = getline(&buffer, &bufferlen, FP);
		check = run_opcode(buf);
	}
	if (glcount == -1 && check == 0)/*if getline fails*/
		myexit(-3);
	if (check < 0)/*if run_opcode fails*/
		myexit(check);
	exit(EXIT_SUCCESS);
	on_exit(dlist_destroy());
	on_exit(free(buffer)), on_exit(close(FD));
}
