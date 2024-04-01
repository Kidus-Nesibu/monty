#include"monty.h"
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE:monty file\n");
		exit(EXIT_FAILURE);
	}
	process_file(argv[1]);
	return 0;
}
void process_file(char *filename)
{
        char *line = NULL;
        size_t len = 0;
        int read;
        unsigned int line_number = 0;
        char *token;

        FILE *file = fopen(filename, "r");
        if (file == NULL)
        {
                fprintf(stderr, "Error: Can't open file %s\n", filename);
                exit(EXIT_FAILURE);
        }
	printf("File is opend --------------------\n");
        while ((read = getline(&line, &len, file)) != -1)
        {
                line_number++;
                token = strtok(line, " \n\t\r");
		printf("Read line %d and tokenized string\n", line_number);
                if (token != NULL)
                {
			printf("calling the check function to check if the opcode is in the array\n");
                        check(token, line_number);
                }
        }
	printf("freeing the getline buffer line\n");
        if (line)
        {
                free(line);
        }
        fclose(file);
}
