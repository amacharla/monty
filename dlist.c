#include "monty.h"
/**
 * dlist_init - initializes doubly linked list
 */
void dlist_init(void)
{
	gs.size = 0;
	gs.ln = 0;
	gs.head = NULL;
	gs.tail = NULL;
	gs.fd = NULL;
	gs.buffer = NULL;
	gs.intarg = 0;
	gs.mode = 1;
}
/**
 * dlist_remove - removes node from doubly linked list
 * @node: stack to be removed
 * Return: 0 on sucess else -1 if stack is empty
 */
int dlist_remove(stack_t *node)
{
	if (node == NULL || gs.size == 0)
		return (-1);
	/*remove element from gs*/
	if (node == gs.head)/* handle removal from head of the list*/
	{
		gs.head = node->next;

		if (gs.head == NULL)
			gs.tail = NULL;
		else
			node->next->prev = NULL;
	}
	else/* handle removal from other than head in gs*/
	{
		node->prev->next = node->next;

		if (node->next == NULL)
			gs.tail = node->prev;
		else
			node->next->prev = node->prev;
	}
	free(node);
	gs.size--;

	return (0);
}
/**
 * dlist_ins_end - adds node to the end ofdoubly linked list
 * @data: int to be stored in node
 * Return: 0 on sucess else 42 if malloc fails
 */
int dlist_ins_end(const int data)
{
	stack_t *new_node, *node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (42);
	/* Add new element into dlist_t */
	new_node->n = data;

	if (gs.size == 0)/*if list is empty*/
	{
		gs.head = new_node;
		gs.head->prev = NULL;
		gs.head->next = NULL;
		gs.tail = new_node;
	}
	else/* -node->prev- -new_node- -node->next- */
	{
		node = gs.tail;
		new_node->next = node->next;
		new_node->prev = node;
		gs.tail = new_node;
		node->next = new_node;
	}
	gs.size++;

	return (0);
}
/**
 * dlist_ins_beg - adds node to beginning of doubly linked list
 * @data: int to be stored in node
 * Return: 0 on sucess else 42 if malloc fails
 */

int dlist_ins_beg(const int data)
{
	stack_t *new_node, *node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (42);
	/* Add new element into dlist_t */
	new_node->n = data;

	if (gs.size == 0)/*if list is empty*/
	{
		gs.head = new_node;
		gs.head->prev = NULL;
		gs.head->next = NULL;
		gs.tail = new_node;
	}
	else/* -node->prev- -new_node- -node->next- */
	{
		node = gs.head;
		new_node->next = node;
		new_node->prev = node->prev;
		gs.head = new_node;
		node->prev = new_node;
	}
	gs.size++;

	return (0);
}
