/**
* nop - function that does nothing
* @head: voided
* @data: voided
*/
void nop(stack_t **head, unsigned int data)
{
	(void)head;
	(void)data;
}
/**
* swap - swaps the top two elements of the stack
* @head: void
* @data: void
*/

void swap(stack_t **head, unsigned int data)
{
	(void)head;
	if (gs.size <= 2)
		myexit(-8, NULL);

	data = gs.tail->n;
	gs.tail->n = gs.tail->prev->n;
	gs.tail->prev->n = data;
}
