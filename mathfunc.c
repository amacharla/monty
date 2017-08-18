#include "monty.h"
/**
  * _add - adds the top two elements of the stack
  * @head: void
  * @data: void
  */
void _add(stack_t **head, unsigned int data)
{
	(void)head;

	if (gs.size < 2)
		myexit(-8, "add");

	data = gs.tail->n;
	dlist_remove(gs.tail);
	data += gs.tail->n;
	gs.tail->n = data;
}
/**
  * _sub - subtract the top two elements of the stack
  * @head: void
  * @data: store interger from node
  */
void _sub(stack_t **head, unsigned int data)
{
	(void)head;

	if (gs.size < 2)
		myexit(-8, "sub");

	data = gs.tail->prev->n;
	data -= gs.tail->n;
	gs.tail->prev->n = data;
	dlist_remove(gs.tail);
}
/**
  * _div - divides the top two elements of the stack
  * @head: void
  * @data: store integer from node
  */
void _div(stack_t **head, unsigned int data)
{
	(void)head;

	if (gs.size < 2)
		myexit(-8, "div");

	data = gs.tail->n;
	if (data == 0)
		myexit(-9, NULL);
	dlist_remove(gs.tail);
	data /= gs.tail->n;
	gs.tail->n = data;
}
/**
  * _mod - modulo the top two elements of the stack
  * @head: void
  * @data: store integer from node
  */
void _mod(stack_t **head, unsigned int data)
{
	(void)head;

	if (gs.size < 2)
		myexit(-8, "mod");

	data = gs.tail->n;
	if (data == 0)
		myexit(-9, NULL);
	dlist_remove(gs.tail);
	data %= gs.tail->n;
	gs.tail->n = data;
}
/**
  * _mul - multiply the top two elements of the stack
  * @head: void
  * @data: store interger from node
  */
void _mul(stack_t **head, unsigned int data)
{
	(void)head;

	if (gs.size < 2)
		myexit(-8, "mul");

	data = gs.tail->n;
	dlist_remove(gs.tail);
	data *= gs.tail->n;
	gs.tail->n = data;
}
