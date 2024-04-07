#include"monty.h"
/**
 * main - entry point of the program
 * @argc: the number of argument that is give to the excutable
 * @argv: the argument value that is given to the excutable
 * Return: 0 if the program succesfully runs
 */
container_t container = {NULL, NULL, 0, 0, NULL, NULL};
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE:monty file\n");
		exit(EXIT_FAILURE);
	}
	process_file(argv[1]);
	return (0);
}
/**
 * process_file - opens and prosess the given file line by line
 * @filename: the name of the file that is give
 */
void process_file(char *filename)
{
	char *line = NULL;
	size_t len = 0;
	int read;
	unsigned int line_number = 0;
	char *token;
	stack_t *top = NULL;
	FILE *file = fopen(filename, "r");
	char *str;

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{	
		line_number++;
		token = strtok(line, " \n\t\r");
		str = strtok(NULL, " \n\t\r");
		container.integral = str;
		container.file  = file;
		container.line = line;
		if (token != NULL)
		{
			check(token, line_number, &top);
		}
	}
	if (line)
	{
		free(line);
	}
	free_stack(top);
	fclose(file);
}
