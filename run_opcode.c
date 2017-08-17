#include "monty.h"
#include <string.h>
#include <ctype.h>
/**
 * run_opcode - searches line for commands and executes them
 * @buf: line of opcode taken from from file
 * Return: 0 success, -3 if not a valid command
 */
int run_opcode(char *buf)
{
	instruction_t cmd[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", _add}, {"nop", nop},
		{"sub", _sub}, {"mul", _mul}, {"div", _div}, {"mod", _mod},
		{NULL, NULL}
	};
	stack_t **head = NULL;
	char *opcode, *argint;
	unsigned int i;
	int intarg = 0;

	opcode = strtok(buf, " \t\n\r");
	if (opcode == NULL)
		return (0);
	for (i = 0; cmd[i].f != NULL; i++)
	{
		if (strcmp(opcode, cmd[i].opcode) == 0)
		{
			if (i == 0)
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
	if (cmd[i].f == NULL)/*IF NO MATCH*/
		myexit(-3, opcode);

	return (0);
}
/**
  * chk_int - checks argument given for push statement is a valid integer
  * @argint: integer given as a string
  * Return: number string converted to integer on success, otherwise -4
  */
int chk_int(const char *argint)
{
	int i, check, intarg;

	if (argint == NULL)
		return (-4);/*second strtok fails*/

	for (i = 0; argint[i]; i++)
	{
		check = isdigit(argint[i]);
		if (check == 0)
			return (-4);
	}
	intarg = atoi(argint);
	return (intarg);
}
/**
  * myexit - prints out error messages and exits failure
  * @code: corresponding error code
  * @string: opcode failure occured on
  **/
void myexit(int code, char *string)
{
	code *= -1;
	switch (code)
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
			printf("L%d: can't %s, stack too short\n", gs.ln, string);
			break;
		case 9:
			printf("L%d: division by zero\n", gs.ln);
	}
	exit(EXIT_FAILURE);

}
/**
 * chk_int - checks argument after opcode for integer value
 * @argint: argument thats being checked to be integer
 * Return: String converted to Integer to be added to stack
 */
int chk_int(const char *argint)
{
	int i, check, intarg;

	if (argint == NULL)
		return (-4);/*second strtok fails*/

	for (i = 0; argint[i]; i++)
	{
		check = isdigit(argint[i]);
		if (check == 0)
			return (-4);
	}
	intarg = atoi(argint);
	return (intarg);
}
/**
* nop - function that does nothing
* @head: voided
* @data: voided
*/
void nop(stack_t **head, unsigned int data)
{
	(void)head;
	(void)data;
}
