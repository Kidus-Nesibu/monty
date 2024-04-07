#include"monty.h"
/**
 * push - push a data to the top of the stack
 * @top: the top of the stack
 * @line_number: the number of the line
 */
void push(stack_t **top, unsigned int line_number)
{
	int data;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (check_for_digit(container.integral) == 1 || container.integral == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		if (*top != NULL)
			free_stack(*top);
		fclose(container.file);
		free(container.line);
		exit(EXIT_FAILURE);
	}
	data = atoi(container.integral);
	container.val_passed = data;

        if (new_node == NULL)
        {
                fprintf(stderr, "Error: malloc failed\n");
                return;
        }
        new_node->n = data;
        new_node->prev = NULL;
        new_node->next = NULL;

        if (*top != NULL)
        {
                (*top)->prev = new_node;
		new_node->next = *top;
        }
        *top = new_node;

	if (*top == NULL)
	{
		*top = new_node;
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
