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
		{"pop", pop},
		{NULL, NULL}
	};
	while (arr[i].opcode != NULL)
	{
		if (strcmp(arr[i].opcode, str) == 0)
		{
			container.argument = str;
			arr[i].f(top, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L:%d unknown instruction %s\n", line_number, str);
	fclose(container.file);
	free(container.line);
	free_stack(*top);
	exit(EXIT_FAILURE);
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
void free_stack(stack_t *top)
{
	stack_t *tmp;
	tmp = top;
	
	while (tmp)
	{
		tmp = top->next;
		free(top);
		top = tmp;
	}
}
