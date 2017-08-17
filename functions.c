#include "monty.h"
/**
  * pall -  prints all the values on the stack, starting from the top
  * @head: void
  * @data: void
  */
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
/**
* pint- prints value on the top of the stack
* @head: void
* @data: void
*/
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
/**
  * push - pushes an element to the stack
  * @head: void
  * @data: integer passed to stack
  */

void push(stack_t **head, unsigned int data)
{
	(void)head;

	dlist_ins_end(data);
}
/**
  * pop - removes the top element of the stack
  * @head: void
  * @data: void
  */
void pop(stack_t **head, unsigned int data)
{
	(void)head;
	(void)data;

	if (gs.size == 0)
		myexit(-7, NULL);
	dlist_remove(gs.tail);
}
/**
  * add - adds the top two elements of the stack
  * @head: void
  * @data: void
  */
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
