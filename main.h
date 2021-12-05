#ifndef _SHELL_H_
#define _SHELL_H_

#define DELIMITER " \t\n"
#define PROMPT "$ "

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <stddef.h>
#include <sys/wait.h>
#include <fcntl.h>

/**
 * struct builtin - Struct builtin
 * @op: The operator
 * @f: The function associated
 */
typedef struct builtin
{
	char *name;
	int (*f)(char **args);
} our_built_in;

int interactive_mode(void);
void split_line(char *line);
int execute(char **command);
void non_interactive_mode();

int get_op_func(char **args);
int built_env(char **args __attribute__((unused)));
int built_exit(char **args __attribute__((unused)));
void handle_signal(int sign __attribute__((unused)));

int _strlen(char *s);
int counter(char *str);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
ssize_t read_textfile(const char *filename, size_t letters);

#endif
