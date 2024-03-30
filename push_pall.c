#include"monty.h"
void push(stack_t **top, int n)
{
	int data;
	stack_t *new = malloc(sizeof(stack_t));

	data = atoi(strtok(NULL, " \n\t\r"));
	new->n = data;
	new->next = *top;
	*top = new;
}
void print(stack_t **top, int n)
{
	stack_t *tmp;
	
	*top = tmp;
	while(tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
