#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <string.h>

#define STACK 0
#define QUEUE 1
#define DELIMITERS " \n\t\a\b"

/* GLOBAL OPCODE TOKENS */
extern char **op_toks;

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

void m_push(stack_t **stack, unsigned int line_number);
void m_pall(stack_t **stack, unsigned int line_number);
void m_pint(stack_t **stack, unsigned int line_number);
void m_pop(stack_t **stack, unsigned int line_number);
void m_swap(stack_t **stack, unsigned int line_number);
void m_add(stack_t **stack, unsigned int line_number);
void m_sub(stack_t **stack, unsigned int line_number);
void m_div(stack_t **stack, unsigned int line_number);
void m_mul(stack_t **stack, unsigned int line_number);
void m_mod(stack_t **stack, unsigned int line_number);
void m_nop(stack_t **stack, unsigned int line_number);
void m_pchar(stack_t **stack, unsigned int line_number);
void m_pstr(stack_t **stack, unsigned int line_number);
void m_rotl(stack_t **stack, unsigned int line_number);
void m_rotr(stack_t **stack, unsigned int line_number);
void m_stack(stack_t **stack, unsigned int line_number);
void m_queue(stack_t **stack, unsigned int line_number);

unsigned int get_toks_len(void);
void free_op_toks(void);
void (*get_opcode_function(char *opcode))(stack_t**, unsigned int);
unsigned int get_absolute_value(int i);
char *int_to_string(int num);
int is_line_empty(char *line, char *delimiters);
void convert_num_to_base(unsigned int num, unsigned int base,
		char *str, int str_size);
int get_digits_in_base(unsigned int num, unsigned int base);
int execute_monty_script(FILE *script_fd);
void add_error_code(int error_code);
int print_usage_error(void);
int print_malloc_error(void);
int print_open_error(char *filename);
int print_inst_error(char *opcode, unsigned int line_number);
int print_invalid_error(unsigned int line_number);
int print_pop_error(unsigned int line_number);
int print_pint_error(unsigned int line_number);
int print_short_stack_error(unsigned int line_number, char *operation);
int print_div_error(unsigned int line_number);
int print_pchar_error(unsigned int line_number, char *message);
int get_mode(stack_t *head);
void free_stack_list(stack_t **stack);
int create_stack_list(stack_t **stack);
char **split_string(char *str, char *delimiters);
int is_delimiter(char ch, char *delimiters);
int get_word_length(char *str, char *delimiters);
int get_num_words(char *str, char *delimiters);
char *get_next_word(char *str, char *delimiters);

#endif
