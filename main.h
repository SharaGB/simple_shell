#ifndef _SHELL_H_
#define _SHELL_H_

#define DELIMITER " \t\n"
#define PROMPT "🧿 $ "

extern char **environ;

#include <stdio.h>	/*perror*/
#include <stdlib.h> /*malloc, free, exit, EXIT_SUCCESS, EXIT_FAILURE*/
#include <unistd.h> /*fork, pid_t, execve, access, getpid*/
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
 * @help: Built-in help
 */
typedef struct builtin
{
	char *name;
	int (*f)(char **args);
	char *help;
} our_built_in;

void split_line(char *str);
int execute(char **command);
void non_interactive_mode(void);

int get_func(char **args);
int built_cd(char **args);
int built_help(char **args);
char *_which(char *command);
int built_env(char **args __attribute__((unused)));
int built_exit(char **args __attribute__((unused)));

void free_args(char **args);
void handle_signal(int sign __attribute__((unused)));

int _strlen(char *s);
int counter(char *str);
char *_strdup(char *str);
char *_str_dup(char *str);
int _strcmp(char *s1, char *s2);
int _strlenconst(const char *s);
char *_getenv(const char *name);
char *str_concat(char *s1, char *s2);
int str_cmp(char *s1, const char *s2);
ssize_t read_textfile(const char *filename, size_t letters);

#endif
