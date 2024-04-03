#include"monty.h"
void check(char *str, unsigned int line_number, stack_t **top)
{
	int i = 0;
	
	instruction_t arr[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	while (arr[i].opcode != NULL)
	{
		if (strcmp(arr[i].opcode, str) == 0)
		{
			arr[i].f(top, line_number);
			return;
		}
		i++;
	}
	if (strcmp(arr[i].opcode, str) != 0)
	{
		fprintf(stderr, "L:%d unknown instruction %s\n", line_number, str);
		exit(EXIT_FAILURE);
	}
}
bool isInteger(double num)
{
	return (num == (int)num);
}
stack_t *add_node(stack_t *top, int data)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	new_node->n = data;
	new_node->prev = NULL;
	new_node->next = NULL;

	new_node->next = top;
	if (top != NULL)
	{
		new_node->prev = top;
	}
	top = new_node;
	return new_node;

}
