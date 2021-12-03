
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

short file_exists(char *filename)
{
  int fd=open(filename, O_RDONLY);
  if (fd==-1)
    {
      if (errno==2)             /* If errno==2 it means file not found */
        return 0;               /* otherwise there is another error at */
      else                      /* reading file, for example path not  */
        return -1;              /* found, no memory, etc */
    }
  close(fd);                    /* If we close the file, it exists */
  return 1;
}

int findInPath(char *result, char *executable)
{
  char *path = getenv("PATH");
  char *saveptr;
  char *tmpstr = malloc(strlen(path)+strlen(executable)+2);
  char *directory = strtok_r(path, ":", &saveptr);
  char *slash = "/";
  short found = 0;
  while ( (directory != NULL) && (!found) )
    {
      sprintf (tmpstr, "%s%s%s", directory, (directory[strlen(directory)-1]=='/')?"":slash, executable);
      if (file_exists(tmpstr))
    found = 1;
      directory = strtok_r(NULL, ":", &saveptr);
    }

  if (found)
    strcpy(result, tmpstr);

  free(tmpstr);

  return found;
}

int main ()
{
  char res[200];
  if (findInPath(res, "ls"))
  {
     printf ("Found at: %s\n", res);
  }
  else
    printf ("Not found!\n");

  return 0;
}
