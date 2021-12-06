#ifndef _SHELL_H_
#define _SHELL_H_

#define DELIMITER " \t\n"
#define PROMPT "$ "

extern char **environ;
static char *search_path[10];
typedef void (*sighandler_t)(int);
static char *my_argv[100], *my_envp[100];

#include <stdio.h>	/*perror*/
#include <stdlib.h> /*malloc, free, exit, EXIT_SUCCESS, EXIT_FAILURE*/
#include <unistd.h> /*fork, pid_t, execve*/
#include <string.h> /*strcmp, strtok*/
#include <signal.h>
#include <stddef.h>
#include <fcntl.h>
#include <sys/wait.h> /*waitpid*/
#include <sys/stat.h> /*stat*/

/**
 * struct builtin - Struct builtin
 * @name: The operator
 * @f: The function associated
 */
typedef struct builtin
{
	char *name;
	int (*f)(char **args);
} our_built_in;

void split_line(char *str);
int execute(char **command);
void non_interactive_mode(void);

int get_func(char **args);
int built_cd(char **args);
int built_env(char **args __attribute__((unused)));
int built_exit(char **args __attribute__((unused)));

void free_args(char **args);

int _strlen(char *s);
int counter(char *str);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *str_concat(char *s1, char *s2);
char **_realloc(char **ptr, size_t *size);
char *_strncat(char *dest, char *src, int n);
ssize_t read_textfile(const char *filename, size_t letters);

#endif
