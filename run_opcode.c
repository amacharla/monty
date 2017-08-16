#include "monty.h"
#include <string.h>
#include <ctype.h>

int run_opcode(char *buf)
{
	instruction_t cmd[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", nop}, {NULL, NULL}
	};
	stack_t *head = NULL;
	char *_opcode, *argint;
	int i, _int, check, chk, intarg = -1;
	dlist_t struct;

	dlist_init();
	_opcode = strtok(buf, " \t\n");
	while(_opcode != NULL)
	{
		for(i = 0; cmd[i].f != NULL; i++)
		{
			if (strcmp(_opcode, cmd[i].opcode) == 0)
			{
				if(i == 0)
				{
					argint = strtok(NULL, " ");
					intarg = chk_int(argint);
					if (intarg == -1)/*CHANGE THIS ERRORCODE*/
						break;
				}
				chk = cmd[i].f(head, intarg);
				break;
			}
		}
		if(cmd[i].f == NULL || intarg == -1)
			return(-1);
	}
	return(chk);
}

int chk_int(const char *argint)
{
	int i, check, intarg;
	if (argint == NULL)
		return (-3)/* CHANGE THIS ERROR CODE*/
	for(i = 0; argint[i]; i++)
	{
		check = isalpha(argint[i]);
		if (check == 0)
			return (-1);
	}
	intarg = atoi(argint);
	return (intarg);
}
