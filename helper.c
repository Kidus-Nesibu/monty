#include"monty.h"
instruction_t arr[] = {
	{"push", push},
	{"pall", print},
	{NULL, NULL}
};
void check(char *str, stack_t **top, int n)
{
	int i = 0;
	while(arr[i] != NULL)
	{
		if (strcmp(arr[i].opcode, str) == 0)
		{
			arr[i].f(&top, data);
		}
		if (arr[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", n, *str);
			exit(EXIT_FAILURE);
		}
		i++;
	}

}

