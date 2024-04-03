#include"monty.h"
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
}
void pall(stack_t **top, unsigned int line_number)
{
	stack_t *tmp = *top;
	UNUSED(line_number);
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
