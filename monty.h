#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>


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

/**
 * struct globals - global functions
 * @lifo: is stack or queue
 * @cont: line count
 * @arg: data to store
 * @head: pointer to doubly linked list
 * @fd: file descriptor
 * @buffer: opcode command
 */

typedef struct globals
{
	int lifo;
	unsigned int line;
	char  *arg;
	stack_t *head;
	FILE *file;
	char buffer[100];
} global_t;

extern global_t glo_var;


void (*get_opcodes(char *opcode))(stack_t **stack, unsigned int line);
void free_glo(void);
void _push(stack_t **stack, unsigned int line);
void _pall(stack_t **stack, unsigned int line);
void _pint(stack_t **stack, unsigned int line);
void free_dlistint(stack_t *head);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
char *_strtok(char *s, char *d);
int _strch(char *s, char c);
void _pop(stack_t **stack, unsigned int line);
void _swap(stack_t **stack, unsigned int line);
void _queue(stack_t **stack, unsigned int line);
void _stack(stack_t **stack, unsigned int line);
void _add(stack_t **stack, unsigned int line);
void _nop(stack_t **stack, unsigned int line);
void _sub(stack_t **stack, unsigned int line);
void _pchar(stack_t **stack, unsigned int line);


#endif
