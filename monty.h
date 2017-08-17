#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>

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
/**
 * struct dlist_s - global structure to hold data
 * @size: size of double linked list
 * @head: pointer to the head of double linked list
 * @tail: pointer to the tail of double linked list
 */
typedef struct dlist_s
{
	size_t size;
	unsigned int ln;
	stack_t *head;
	stack_t *tail;
	FILE *fd;
	char *buffer;
} dlist_t;

extern dlist_t gs;

/* Double Linked List Functions*/
void dlist_init(void);
void dlist_destroy(void);
int dlist_ins_end(const unsigned int data);
int dlist_ins_beg(const unsigned int data);
int dlist_remove(stack_t *node);

/* Functions.c */
void myexit(int code, char *string);
int run_opcode(char *buf);
int chk_int(const char *argint);
void push(stack_t **stack, unsigned int data);
void pint(stack_t **stack, unsigned int data);
void pall(stack_t **stack, unsigned int data);
void pop(stack_t **stack, unsigned int data);
void nop(stack_t **stack, unsigned int data);
void add(stack_t **head, unsigned int data);
void swap(stack_t **head, unsigned int data);


#endif /* _MONTY_H_ */
