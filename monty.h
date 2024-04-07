#ifndef MAIN_H
#define MAIN_H
#define UNUSED(x) (void)(x)
#include<unistd.h>
#include<ctype.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<string.h>
#include<stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
typedef struct container_h
{
	char *argument;
	char *integral;
	int val_passed;
	unsigned int count;
	FILE *file;
	char *line;
}container_t;
extern container_t container;
void process_file(char *filename);
void check(char *str, unsigned int line_number, stack_t **top);
void push(stack_t **top, unsigned int line_number);
void pall(stack_t **top, unsigned int line_number);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
int check_for_digit(char *num);
void pint(stack_t **top, unsigned int line_number);
void pop(stack_t **top, unsigned int line_number);
void free_stack(stack_t *top);
#endif
