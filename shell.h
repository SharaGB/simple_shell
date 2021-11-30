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

void *split_line(char *str, char **str_list);
void handle_signal(int sign __attribute__((unused)));
int execute(const char *pathname, char **argv, char **environ);

int found_PATH(char *pathname, int mode);
int get_path(char *pathname, char *paths);

int _strlen(char *s);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif
