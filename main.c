#include "monty.h"

int main(int ac, char **av)
{
	char *m_file = fopen(av[1], r);
	if (ac != 2 || m_file == NULL)
	{
		myexit(1);
	}
	while(check != -1)
	{
		linecount++;
		check = getline(buf, len, m_file);
		check = run_opcode(stack, buf);
	}
	while(check)
}
