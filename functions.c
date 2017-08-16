#include "monty.h"

extern dlist_t gstruct;

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
size_t pall(void)
{
	unsigned int i = 0;
	stack_t *list = gstruct.head;

	for (; list; list = list->next, i++)
	{
		printf("%d\n", list->n);
	}
	return (i);
}
size_t pint(void)
{
	stack_t *list = gstruct.head;

	printf("%d\n", list->n);

	return (0);
}
