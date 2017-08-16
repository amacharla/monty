#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Double Linked List Functions*/
void dlist_init(stack_t *list);
void dlist_destroy(stack_t *list);
int dlist_ins_end(stack_t *list, const unsigned int data);
int dlist_ins_beg(stack_t *list, const unsigned int data);
int dlist_remove(stack_t *list, stack_t *node);

/* Functions.c */
void myexit(int code, int linenum, char *string);
int run_opcode(char *buf);
int chk_int(char *x);
/*Macros*/
#define dlist_size(list) ((list)->size)
#define dlist_is_head(node) ((node)->prev == NULL ? 1 : 0)
#define dlist_is_tail(node) ((node)->next == NULL ? 1 : 0)

#endif /* _MONTY_H_ */
