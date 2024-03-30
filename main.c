#include"monty.h"
int main(int argc, char *argv[])
{
	char *line = NULL;
	FILE *file;
	char *opcode;
	int  read;
	stack_t **top = NULL;
	size_t len = 0;
	int line_num = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (opcode == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	while(read = getline(&line, &len, file) != -1)
	{
		line_num++;
		opcode = strtok(line, " \n\t\r");
		if (opcode != NULL)
		{
			check(opcode, top, line_num);
		}
	}
	
	fclose(file);
	exit(EXIT_SUCCESS);
	return (0);
}

