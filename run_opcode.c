#include "monty.h"
#include <string.h>
#include <ctype.h>

int runopcode(char *buf)
{
	instruction_t cmd[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", nop}, {NULL, NULL}
	};
	stack_t *head = NULL;
	char *opcode, *argint;
	int i, chk = 0, intarg = -1;

	dlist_init();/*initilize gstruct*/
	opcode = strtok(buf, " \t\n");
	if (opcode == NULL)
		return (-3);
	while(opcode != NULL)
	{
		for(i = 0; cmd[i].f != NULL; i++)
		{
			if (strcmp(opcode, cmd[i].opcode) == 0)
			{
				if(i == 0)
				{
					argint = strtok(NULL, " ");
					intarg = chk_int(argint);/*check for int argument*/
					if (intarg == -4)/*CHANGE THIS ERRORCODE*/
						myexit(-3, opcode);
				}
				cmd[i].f(head, intarg);/*send to respective funciton*/
				break;
			}
		}
		if(cmd[i].f == NULL)/*IF NO MATCH*/
			myexit(-3, opcode);
	}
	return(chk);
}

int chk_int(const char *argint)
{
	int i, check, intarg;
	if (argint == NULL)
		return (-4)/* CHANGE THIS ERROR CODE*/
	for(i = 0; argint[i]; i++)
	{
		check = isalpha(argint[i]);
		if (check == 0)
			return (-4);
	}
	intarg = atoi(argint);
	return (intarg);
}
