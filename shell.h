#ifndef _SHELL_H_
#define _SHELL_H_
#define BUFSIZE 1024
#define TOK_BUFSIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>

int interactive_mode(void);
void *split_line(char *str, char **str_list);
void handle_signal(int sign __attribute__((unused)));
int execute(const char *pathname, char **argv, char **environ);

int _strlen_recursion(char *s);
char *_strncpy(char *dest, char *src, int n);
char *_realloc(char *old, int len, int newlen);
char *_memcpy(char *dest, char *src, unsigned int n);


#endif
