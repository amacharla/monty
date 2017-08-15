#include "monty.h"
#include <string.h>

void dlist_init (dlist_t *list)
{
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
}

void dlist_destroy (dlist_t *list)
{
	void *data;

	while (dlist_size(list) > 0) /* remove each element */
		if (dlist_remove(list, list->tail) == 0)

	memset(list, 0, sizeof(dlist_t));
}

int dlist_remove (dlist_t *list, struct_t *node)
{
	if (element == NULL || dlist_size(list) == 0)
		return (-1);
	/*remove element from list*/
	if (node == list->head)/* handle removal from head of the list*/
	{
		list->head = next(node);

		if (list->head == NULL)
			list->tail = NULL;
		else
			next(node)_prev = NULL;
	}
	else/* handle removal from other than head in list*/
	{
		prev(node)_next = next(node);

		if (next(node) == NULL)
			list->tail = prev(node);
		else
			next(node)_prev = prev(node);
	}
	free(node);
	list->size--;

	return 0;
}

int dlist_ins_next (dlist_t *list, struct_t *node, const int data)
{
	struct_t *new_node;

	if (node == NULL && dlist_size(list)!= 0)
		return (-1);

	new_node = malloc(sizeof(struct_t))
	if (new_node == NULL)
		return (-1);
	/* Add new element into dlist_t */
	new_node->data = data;

	if (dlist_size(list) == 0)/*if list is empty*/
	{
		list->head = new_node;
		list->head->prev = NULL;
		list->head->next = NULL;
		list->tail = new_node;
	}
	else/* -prev(node)- -new_node- -next(node)- */
	{
		new_node->next = next(node);
		new_node->prev = node;

		if (next(node) == NULL)
			list->tail = new_node;
		else
			next(node)_prev = new_node;
		next(node) = new_node;
	}
	list->size++;

	return (0);
}


int dlist_ins_prev (dlist_t *list, struct_t *node, const int data)
{
	struct_t *new_node;

	if (node == NULL && dlist_size(list)!= 0)
		return (-1);

	new_node = malloc(sizeof(struct_t))
	if (new_node == NULL)
		return (-1);
	/* Add new element into dlist_t */
	new_node->data = data;

	if (dlist_size(list) == 0)/*if list is empty*/
	{
		list->head = new_node;
		list->head->prev = NULL;
		list->head->next = NULL;
		list->tail = new_node;
	}
	else/* -prev(node)- -new_node- -next(node)- */
	{
		new_node->next = node;
		new_node->prev = prev(node);

		if (prev(node) == NULL)
			list->head = new_node;
		else
			prev(node)_next = new_node;
		prev(node) = new_node;
	}
	list->size++;

	return (0);
}
