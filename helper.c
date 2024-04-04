#include"monty.h"
/**
 * check - checks if the crossponding of the opcode is available
 * @str: the name of the opcode
 * @line_number: the number of the line
 * @top: the name of the stack
 */
void check(char *str, unsigned int line_number, stack_t **top)
{
	int i = 0;

	instruction_t arr[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
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
/**
 * add_node - add a node to the top of the stack
 * @top: the stack name
 * @data: the data to be added to the stack
 * Return: the new node that is added
 */
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
	return (new_node);

}
/**
 * check_for_digit - checks if the argument is an int or not
 * @num: the argument given to be checked
 * Return: 1 if not an integer 0 if is integer
 */
int check_for_digit(char *num)
{
	int i;

	if (num == NULL)
	{
		return (1);
	}
	for (i = 0; num[i] != '\0'; i++)
	{
		if (i == 0 && num[i] == '-')
		{
			continue;
		}
		if (!isdigit(num[i]))
		{
			return (1);
		}
	}
	return (0);
}
