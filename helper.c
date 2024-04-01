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
	printf("Itreating the array to check if the array cointains the same opcode\n");
	printf("Before the loop\n");
	while (arr[i].opcode != NULL)
	{
		printf("in the loop ...\n");
		if (strcmp(arr[i].opcode, str) == 0)
		{
			printf("calling the function to perform the crossponding operation\n");
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
