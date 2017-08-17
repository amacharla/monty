#include "monty.h"


void myexit(int code, char *string)
{
	code *= -1;
	switch(code)
	{
		case 1:
			printf("USAGE: monty file\n");
			break;
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
void pall(stack_t **head, unsigned int data)
{
	unsigned int i = 0;
	stack_t *list = gs.head;
	(void)head;
	(void)data;

	for (; list; list = list->next, i++)
	{
		printf("%d\n", list->n);
	}
}

void pint(stack_t **head, unsigned int data)
{
	(void)head;
	(void)data;
/*	stack_t *list = gs.tail;*/
	printf("PINT FUNCTION\n");
/*	printf("%d\n", list->n);*/
}

void push(stack_t **head, unsigned int data)
{
	(void)head;
	(void)data;
	printf("PUSH FUNCTION\n");
}
