#include"monty.h"
#include<stdio.h>
#include<stdlib.h>
void process_file(char *filename)
{
	char *line = NULL;
	size_t len = 0;
	signed int read;
	unsigned int line_number = 1;
	char *token;
	
	FILE *file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		token = strtok(line, " \n\t\r");
		if (token != NULL)
		{
			check(token, line_number);
		}
	}
	
	if (line)
	{
		free(line);
	}
	fclose(file);
}
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
