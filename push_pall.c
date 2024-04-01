#include"monty.h"
void push(stack_t **top, unsigned int line_number)
{
	int data;
	stack_t *new = NULL;
	
	data = atoi(strtok(NULL, " \n\t\r"));
	printf("%d\n", data);
	new = malloc(sizeof(stack_t));
	new->n = data;
	new->prev = NULL;
	new->next = NULL;
		new->next = *top;
		(*top)->prev = new;
		*top = new;
}
void print(stack_t **top, unsigned int line_number)
{
	stack_t *tmp = NULL;

	tmp = *top;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
