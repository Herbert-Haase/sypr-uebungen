#include "fileinfo.h"
#include "queue.h"
// #define N 200

static void list_directory(const char *filename, fileinfo *cd);
static void print_regular(const char *dateiname, const size_t groesse);
static void print_directory(const char *pfad, const char *dateiname,
                            const fileinfo *fi);
static void print_other(const char *dateiname);
void fileinfo_destroy(fileinfo *fi);

fileinfo *fileinfo_create(const char *filename) {
  errno = 0;

  fileinfo *file_i = malloc(sizeof(fileinfo));
  if (strlen(filename) > NAME_MAX) {
    errno = ENAMETOOLONG;
    perror(filename);
    return NULL;
  }
  strcpy(file_i->dateiname, filename);

  struct stat s;
  intmax_t bytes = 0;

  if (lstat(filename, &s) == -1) {
    perror(filename);
    return NULL;
  }
  if (S_ISREG(s.st_mode)) {
    bytes = s.st_size;
    file_i->filetype_regular = bytes;
    file_i->type = filetype_regular;
    return file_i;

  } else if (S_ISDIR(s.st_mode)) {
    file_i->type = filetype_directory;
    list_directory(filename, file_i);
    return file_i;
  } else {
    file_i->type = filetype_other;
    return file_i;
  }
}

static void list_directory(const char *filename, fileinfo *cd) {
  if (strcmp(filename, ".") == 0 || strcmp(filename, "..") == 0) {
    return;
  }
  errno = 0;
  DIR *d = opendir(filename);
  if (!d) {
    perror(filename);
    exit(EXIT_FAILURE);
  }
  chdir(filename);

  struct dirent *e;
  while ((e = readdir(d)) != NULL) {
    //  printf("%s/%s\n", filename, e->d_name);
    cd->next = fileinfo_create(e->d_name);
  }
  if (errno) {
    perror(filename);
    closedir(d);
    exit(EXIT_FAILURE);
  }
  chdir("../");
  if (closedir(d) == -1) {
    perror(filename);
    exit(EXIT_FAILURE);
  }
}

void fileinfo_print(const fileinfo *fi) {
  static Queue q = {.size = 0, .max_size = N, .front = 0, .back = N - 1};
  if (fi->type == filetype_directory) {
    print_directory("", fi->dateiname, fi);
  } else if (fi->type == filetype_regular) {
    print_regular(fi->dateiname, fi->filetype_regular);
  } else if (fi->type == filetype_other) {
    print_other(fi->dateiname);
  }
}

static void print_regular(const char *dateiname, const size_t groesse) {
  printf("%s (regular, %zu Byte)\n", dateiname, groesse);
}

static void print_directory(const char *pfad, const char *dateiname,
                            const fileinfo *fi) {}

static void print_other(const char *dateiname) {
  printf("%s (other)\n", dateiname);
}


void fileinfo_destroy(fileinfo *fi){
  if(fi->type == filetype_directory) {
    fileinfo_destroy(fi->filetype_directory);
  }
  while(fi) {
    fileinfo *next = fi->next;
    free(fi);
    fi = next;
  }
}
