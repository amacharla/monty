#include "monty.h"
/**
 * rotl - rotates the stack to the top
 * @head: beginning of stack
 * @data: integer in stack
 */
void rotl(stack_t **head, unsigned int data)
{
	(void) head;
	if (gs.size == 0)
		myexit(0, NULL);

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
	if (gs.size == 0)
		myexit(0, NULL);

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
	int num;
	(void) head;
	(void) data;

	if (gs.size == 0)
		myexit(-6, "pchar");
	num = gs.tail->n;
	if (num < 0 || num > 127)
		myexit(-10, NULL);
	printf("%c\n", num);
}
/**
 * pstr - rotates the stack to the bottom
 * @head: beginning of stack
 * @data: integer in stack
 */
void pstr(stack_t **head, unsigned int data)
{
	stack_t *list;
	(void) head;
	(void) data;

	list = gs.tail;
	for (; list; list = list->prev)
	{
		if (list->n == 0)
			break;
		printf("%c", list->n);
	}
	printf("\n");
}
/**
 * chgmode - change mode: stack to que
 * @head: Unused
 * @data: Unused
 */
void chgmode(stack_t **head, unsigned int data)
{
	(void) head;
	(void) data;

	gs.mode *= -1;
}
