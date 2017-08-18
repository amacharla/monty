#include "monty.h"
/**
 * rotl - rotates the stack to the top
 * @head: beginning of stack
 * @data: integer in stack
 */
void rotl(stack_t **head, unsigned int data)
{
	(void) head;

	data = gs.tail->n;
	dlist_ins_beg(data);
	dlist_remove(gs.tail);
}
/**
 * rotr - rotates the stack to the bottom
 * @head: beginning of stack
 * @data: integer in stack
*/
void rotr(stack_t **head, unsigned int data)
{
	(void) head;

	data = gs.head->n;
	dlist_ins_end(data);
	dlist_remove(gs.head);
}
/**
 * pchar - rotates the stack to the bottom
 * @head: beginning of stack
 * @data: integer in stack
*/
void pchar(stack_t **head, unsigned int data)
{
	(void) head;
	(void) data;

	printf("%c\n", gs.head->n);
}
/**
 * pstr - rotates the stack to the bottom
 * @head: beginning of stack
 * @data: integer in stack
 */
void pstr(stack_t **head, unsigned int data)
{
	(void) head;
	(void) data;

	stack_t *list = gs.tail;

	for (; list; list = list->prev)
	{
		printf("%c", list->n);
	}
	printf("\n");
}
