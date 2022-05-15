#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

extern int errno;

int main() {
  DIR *dir = opendir(".");

  if (dir == 0) {
    fprintf(stderr, "open cwd fail, %s\n", strerror(errno));
    return 1;
  }

  struct dirent *entry;

  while ((entry = readdir(dir))) {
    fprintf(stdout, "%s\n", entry->d_name);
  }

  return 0;
}
