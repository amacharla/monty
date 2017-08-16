#include "monty.h"
#include <string.h>

void dlist_init(dlist_t *list)
{
	dlist_t list;

	list.size = 0;
	list.head = NULL;
	list.tail = NULL;
}

void dlist_destroy()
{
	dlist_t list;

	while (dlist_size(list) > 0) /* remove each element */
		if (dlist_remove(list, list->tail) == 0)

	memset(list, 0, sizeof(dlist_t));
}

int dlist_remove (stack_t *node)
{
	dlist_t list;

	if (node == NULL || dlist_size(list) == 0)
		return (-1);
	/*remove element from list*/
	if (node == list->head)/* handle removal from head of the list*/
	{
		list->head = node->next;

		if (list->head == NULL)
			list->tail = NULL;
		else
			node->next->prev = NULL;
	}
	else/* handle removal from other than head in list*/
	{
		node->prev->next = node->next;

		if (node->next == NULL)
			list->tail = node->prev;
		else
			node->next->prev = node->prev;
	}
	free(node);
	list->size--;

	return 0;
}

int dlist_ins_end (dlist_t *list, const unsigned int data)
{
	stack_t *new_node, *node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (-1);
	/* Add new element into dlist_t */
	new_node->n = data;

	if (dlist_size(list) == 0)/*if list is empty*/
	{
		list->head = new_node;
		list->head->prev = NULL;
		list->head->next = NULL;
		list->tail = new_node;
	}
	else/* -node->prev- -new_node- -node->next- */
	{
		node = list->tail;
		new_node->next = node->next;
		new_node->prev = node;
		list->tail = new_node;
		node->next = new_node;
	}
	list->size++;

	return (0);
}


int dlist_ins_beg (dlist_t *list, const unsigned int data)
{
	stack_t *new_node, *node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (-1);
	/* Add new element into dlist_t */
	new_node->n = data;

	if (dlist_size(list) == 0)/*if list is empty*/
	{
		list->head = new_node;
		list->head->prev = NULL;
		list->head->next = NULL;
		list->tail = new_node;
	}
	else/* -node->prev- -new_node- -node->next- */
	{
		node = list->head;
		new_node->next = node;
		new_node->prev = node->prev;
		list->head = new_node;
		node->prev = new_node;
	}
	list->size++;

	return (0);
}
