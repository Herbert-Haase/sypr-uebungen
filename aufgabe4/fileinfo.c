#include "fileinfo.h"
#include <dirent.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

static void list_directory(const char *filename);
fileinfo *fileinfo_create(const char *filename);

fileinfo *fileinfo_create(const char *filename) {
  errno = 0;
  FILE *file = fopen(filename, "rb");
  if (file == NULL)
    return NULL;
  if (strlen(filename) > NAME_MAX) {
    errno = ENAMETOOLONG;
    return EXIT_FAILURE;
  }
  fileinfo *file_i = malloc(sizeof(fileinfo));
  strcpy(file_i->dateiname, filename);

  struct stat s;
  intmax_t bytes = 0;

  if (lstat(filename, &s) == -1) {
    perror("stat");
    exit(EXIT_FAILURE);
  }
  if (S_ISREG(s.st_mode)) {
    bytes = s.st_size;
    file_i->filetype_regular = bytes;
    file_i->type = filetype_regular;

  } else if (S_ISDIR(s.st_mode)) {
    file_i->type = filetype_directory;
    list_directory(filename);
  }
}

static void list_directory(const char *filename) {
  if (strcmp(filename, ".") == 0 || strcmp(filename, "..") == 0) {
    return;
  }
  errno = 0;
  chdir(filename);
  DIR *d = opendir(filename);
  if (!d)
    exit(EXIT_FAILURE);

  struct dirent *e;
  while ((e = readdir(d)) != NULL) {
    printf("%s/%s\n", filename, e->d_name);
  }
  if (errno)
    exit(EXIT_FAILURE);
  if (closedir(d) == -1)
    exit(EXIT_FAILURE);

  chdir("../");
}
