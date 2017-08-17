#include "monty.h"
#include <string.h>
#include <ctype.h>

int run_opcode(char *buf)
{
	instruction_t cmd[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, /*{"pop", pop},*/
		/*{"swap", swap}, {"add", add}, {"nop", nop},*/ {NULL, NULL}
	};
	stack_t **head = NULL;
	char *opcode, *argint;
	unsigned int i;
	int intarg = 0;

	opcode = strtok(buf, " \t\n");
	if (opcode == NULL)
		return (-3);
	for(i = 0; cmd[i].f != NULL; i++)
	{
		if (strcmp(opcode, cmd[i].opcode) == 0)
		{
			if(i == 0)
			{
				argint = strtok(NULL, " ");
				intarg = chk_int(argint);/*check for int argument*/
				if (intarg == -4)/*CHANGE THIS ERRORCODE*/
					myexit(-4, opcode);
			}
			cmd[i].f(head, (unsigned int) intarg);/*send to respective funciton*/
			break;
		}
	}
	if(cmd[i].f == NULL)/*IF NO MATCH*/
		myexit(-3, opcode);

	return(0);
}

int chk_int(const char *argint)
{
	int i, check, intarg;
	if (argint == NULL)
		return (-4);/*second strtok fails*/
	for(i = 0; argint[i]; i++)
	{
		check = isalpha(argint[i]);
		if (check == 0)
			return (-4);
	}
	intarg = atoi(argint);
	return (intarg);
}
