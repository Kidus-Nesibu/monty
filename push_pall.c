#include"monty.h"
void push(stack_t **top, unsigned int line_number)
{
	int data;
	data = atoi(strtok(NULL, " \n\t\r"));
	printf("%d\n", data);
 	*top = add(*top, data);

}
void print(stack_t **top, unsigned int line_number)
{
	stack_t *tmp = *top;
	UNUSED(line_number);
	printf("the function is called\n");
	if (tmp == NULL)
	{
		return;
	}
	printf("the stack is not null\n");

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
