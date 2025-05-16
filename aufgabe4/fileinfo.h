#ifndef FILEINFO_H
#define FILEINFO_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

extern int errno;
enum filetype {
  filetype_regular,
  filetype_directory,
  filetype_other,
};

typedef struct fileinfo {
  enum filetype type;
  union {
    size_t filetype_regular;
    struct fileinfo *filetype_directory;
  };
  char dateiname[NAME_MAX + 1];
  struct fileinfo *next;
} fileinfo;

fileinfo *fileinfo_create(const char *filename);

#endif
