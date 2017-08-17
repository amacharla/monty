#include "monty.h"

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
	stack_t *list;

	(void)head;
	(void)data;
	list = gs.tail;
	printf("%d\n", list->n);
}

void push(stack_t **head, unsigned int data)
{
	(void)head;
	dlist_ins_end(data);
}

void add(stack_t **head, unsigned int data)
{
	(void)head;
	if (gs.size == 0)
		myexit(-9, NULL);

	data = gs.tail->n;
	dlist_remove(gs.tail);
	data += gs.tail->n;
	gs.tail->n = data;
}

void nop(stack_t **head, unsigned int data)
{
	(void)head;
	(void)data;
}

void swap(stack_t **head, unsigned int data)
{
	(void)head;
	if (gs.size <= 2)
		myexit(-8, NULL);

	data = gs.tail->n;
	gs.tail->n = gs.tail->prev->n;
	gs.tail->prev->n = data;
}
