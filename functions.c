#include "monty.h"

void myexit(int code, int linenum, char *string)
{
	switch(code)
	{
		case 1:
			perror("USAGE: monty file");
		case 2:
			printf("Error: Cant't open file %s\n", string);
		case 3:
			printf("L%d: unknown instruction %s\n", linenum, string);
		case 4:
			perror("Error: malloc failed");

		exit(EXIT_FAILURE);
	}

}
size_t pall(stack_t *h)
{
	unsigned int i = 0;
	stack_t *list = h;

	for (; list; list = list->next, i++)
	{
		printf("%d\n", list->n);
	}
	return (i);
}
size_t pint(stack_t *h)
{
	stack_t *list = h;

	printf("%d\n", list->n);

	return (0);
}
