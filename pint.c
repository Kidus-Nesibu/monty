#include"monty.h"
/**
 * pint - print the top of the stack without deleting
 * @top: the name of the stack
 * @line_number: the number of the line
 */
void pint(stack_t **top, unsigned int line_number)
{
	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*top)->n);

}
