#include "monty.h"
#include <string.h>
#include <ctype.h>

int run_opcode(char *buf)
{
	instruction_t cmd[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", nop}, {"\n", nop}, {NULL, NULL}
	};
	stack_t **head = NULL;
	char *opcode, *argint;
	unsigned int i;
	int intarg = 0;

	opcode = strtok(buf, " \t");
	if (opcode == NULL)
		return (-3);
	for(i = 0; cmd[i].f != NULL; i++)
	{
		if (strcmp(opcode, cmd[i].opcode) == 0)
		{
			if(i == 0)
			{
				argint = strtok(NULL, " \t\n");
				intarg = chk_int(argint);/*check for int argument*/
				if (intarg == -4)
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
		check = isdigit(argint[i]);
		if (check == 0)
			return (-4);
	}
	intarg = atoi(argint);
	return (intarg);
}

void myexit(int code, char *string)
{
	code *= -1;
	switch(code)
	{
		case 1:
			printf("USAGE: monty file\n"); break;
		case 2:
			printf("Error: Cant't open file %s\n", string);
			break;
		case 3:
			printf("L%d: unknown instruction %s\n", gs.ln, string);
			break;
		case 4:
			printf("L%d: usage: push integer\n", gs.ln);
			break;
		case 5:
			printf("Error: malloc failed\n");
			break;
		case 6:
			printf("L%d: can't pint, stack empty\n", gs.ln);
			break;
		case 7:
			printf("L%d: can't pop an empty stack\n", gs.ln);
			break;
		case 8:
			printf("L%d: can't swap, stack too short\n", gs.ln);
			break;
		case 9:
			printf("L%d: can't add, stack too short\n", gs.ln);
			break;
	}
	exit(EXIT_FAILURE);

}
