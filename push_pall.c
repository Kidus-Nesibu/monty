#include"monty.h"
/**
 * push - push a data to the top of the stack
 * @top: the top of the stack
 * @line_number: the number of the line
 */
void push(stack_t **top, unsigned int line_number)
{
	int data;

	data = atoi(strtok(NULL, " \n\t\r"));
	if (isInteger(data) == false && *top == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	*top = add_node(*top, data);
	if (*top == NULL)
	{
		exit(EXIT_FAILURE);
	}
}
/**
 * pall - prints all of the data from the stack
 * @top: the top of the stack
 * @line_number: the number of the line
 */
void pall(stack_t **top, unsigned int line_number)
{
	stack_t *tmp = *top;

	UNUSED(line_number);
	if (*top == NULL)
	{
		return;
	}
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
