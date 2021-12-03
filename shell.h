#ifndef _SHELL_H_
#define _SHELL_H_

#define DELIMITER " \r\t\n"
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

int interactive_mode(void);
void split_line(char *line);
int execute(char **command);
void non_interactive_mode();

void handle_signal(int sign __attribute__((unused)));

int _strlen(char *s);
int counter(char *str);

#endif
