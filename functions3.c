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
