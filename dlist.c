#include "monty.h"
#include <string.h>
extern dlist_t list;
void dlist_init(void)
{
	list.size = 0;
	list.head = NULL;
	list.tail = NULL;
}

void dlist_destroy(void)
{
	while (list.size > 0) /* remove each element */
		dlist_remove(list.tail);
}

int dlist_remove(stack_t *node)
{
	if (node == NULL || list.size == 0)
		return (-1);
	/*remove element from list*/
	if (node == list.head)/* handle removal from head of the list*/
	{
		list.head = node->next;

		if (list.head == NULL)
			list.tail = NULL;
		else
			node->next->prev = NULL;
	}
	else/* handle removal from other than head in list*/
	{
		node->prev->next = node->next;

		if (node->next == NULL)
			list.tail = node->prev;
		else
			node->next->prev = node->prev;
	}
	free(node);
	list.size--;

	return 0;
}

int dlist_ins_end(const unsigned int data)
{
	stack_t *new_node, *node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (-1);
	/* Add new element into dlist_t */
	new_node->n = data;

	if (list.size == 0)/*if list is empty*/
	{
		list.head = new_node;
		list.head->prev = NULL;
		list.head->next = NULL;
		list.tail = new_node;
	}
	else/* -node->prev- -new_node- -node->next- */
	{
		node = list.tail;
		new_node->next = node->next;
		new_node->prev = node;
		list.tail = new_node;
		node->next = new_node;
	}
	list.size++;

	return (0);
}


int dlist_ins_beg(const unsigned int data)
{
	stack_t *new_node, *node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (-1);
	/* Add new element into dlist_t */
	new_node->n = data;

	if (list.size == 0)/*if list is empty*/
	{
		list.head = new_node;
		list.head->prev = NULL;
		list.head->next = NULL;
		list.tail = new_node;
	}
	else/* -node->prev- -new_node- -node->next- */
	{
		node = list.head;
		new_node->next = node;
		new_node->prev = node->prev;
		list.head = new_node;
		node->prev = new_node;
	}
	list.size++;

	return (0);
}
