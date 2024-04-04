#include"monty.h"
/**
 * pop - pop the node at the top of the stack
 * @top: the name of the stack
 * @line_number: the number of the line
 */
void pop(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *top;
	if (tmp->next != NULL)
	{
		tmp->next->prev = NULL;
	}
	*top = (*top)->next;
	free(tmp);
}
