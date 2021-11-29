#include "shell.h"
/**
 * @brief 
 * 
 * @return char* 
 */
char *read_line(void)
{
    int count;
    int size = BUFSIZE;
    int position = 0;
    char *buffer = malloc(size * sizeof(char));

    if (!buffer)
    {
        fprintf(stderr, "./shell: No such file or directory\n");
        exit(EXIT_FAILURE);
    }
    while (1)
    {
        count = getchar();
        {
            if (count == EOF | count == '\n')
            {
                buffer[position] = '\0';
                return (buffer);
            }
            else
            {
                buffer[position] = count;
            }
            position++;

            if (position >= size)
            {
                size += BUFSIZE;
                buffer = realloc(buffer, size);

            }
        }
    }
}
