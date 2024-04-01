#include"monty.h"
void check(char *str, unsigned int line_number)
{
	stack_t *top = NULL;
	int i = 0;
	
	instruction_t arr[] = {
		{"push", push},
		{"pall", print},
		{NULL, NULL}
	};
	while (arr[i].opcode != NULL)
	{
		printf("%s\n", arr[i].opcode);
		if (strcmp(arr[i].opcode, str) == 0)
		{
			arr[i].f(&top, line_number);
			break;
		}
		i++;
	}
	if (strcmp(arr[i].opcode, str) != 0)
	{
		fprintf(stderr, "L:%d unknown instruction %s\n", line_number, str);
		exit(EXIT_FAILURE);
	}
}
stack_t *add(stack_t *top, int data)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	new_node->n = data;
	new_node->prev = NULL;
	new_node->next = NULL;
	
	new_node->next = top;
	if (top != NULL)
	{
		top->prev = new_node;
	}
	return new_node;
}
	
