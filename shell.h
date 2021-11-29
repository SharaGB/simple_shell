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
void split_line(char *str, char **str_list);
void handle_signal(int sign __attribute__((unused)));
int execute(const char *pathname, char **argv, char **environ);


#endif
