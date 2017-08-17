#include "monty.h"

void pall(stack_t **head, unsigned int data)
{
	stack_t *list;
	(void)head;
	(void)data;

	list = gs.tail;
	if (gs.size == 0)
		myexit(0, NULL);
	for (; list; list = list->prev)
		printf("%d\n", list->n);
}

void pint(stack_t **head, unsigned int data)
{
	stack_t *list;
	(void)head;
	(void)data;

	if (gs.size == 0)
		myexit(-6, NULL);

	list = gs.tail;
	printf("%d\n", list->n);
}

void push(stack_t **head, unsigned int data)
{
	(void)head;

	dlist_ins_end(data);
}

void pop(stack_t **head, unsigned int data)
{
	(void)head;
	(void)data;

	if (gs.size == 0)
		myexit(-7, NULL);
	dlist_remove(gs.tail);
}

void add(stack_t **head, unsigned int data)
{
	(void)head;

	if (gs.size <= 2)
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
