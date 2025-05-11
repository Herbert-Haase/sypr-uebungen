#include "fileinfo.h"
#include <stdint.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

static fileinfo* list_directory(const char* filename);

fileinfo *fileinfo_create(const char *filename) {
  FILE *file = fopen(filename, "rb");
  if (file == NULL)
    return NULL;
  if (strlen(filename) > NAME_MAX)
    errno = ENAMETOOLONG;

  struct stat s;
  intmax_t bytes = 0;

  if (lstat(filename, &s) == -1) {
    perror("stat");
    exit(EXIT_FAILURE);
  }
    if(!S_ISDIR(s.st_mode)) {
        bytes = s.st_size;
    } else {

    }
}

static fileinfo* list_directory(const char* filename) {

}
