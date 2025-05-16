// stringsort.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void bubblesort(void *a, int n, int m, int (*cmp)(const void *, const void *));

int main(int argc, const char *argv[]) {
  if (argc != 2) {
    printf("Aufruf: %s Anzahl\n", argv[0]);
    printf("Anzahl muss mindestens 1 sein\n");
    return EXIT_FAILURE;
  }

  int n = atoi(argv[1]);
  int m = strlen(argv[1]) + 1;
  if (n < 1) {
    printf("Anzahl muss mindestens 1 sein\n");
    return EXIT_FAILURE;
  }
  char *a = malloc(n * m * sizeof(char));
  if (!a) {
    fprintf(stderr, "out of memory");
    exit(1);
  }
  srand(time(NULL));

  puts("Unsortierte Array:");

  // fill array with random values
  for (int i = 0; i < n; ++i) {
    int r = rand() % n;
    char *pos = a + i * m;
    snprintf(pos, m, "%d", r);
    printf("%s ", pos);
  }
  puts("\nSorted");
  typedef int (*cmp)(const void*, const void*);
  bubblesort((void *)a, n, m, (cmp) strcmp);

  char *strbuilder = malloc(n * m * sizeof(char));
  if (!strbuilder) {
    fprintf(stderr, "out of memory");
    exit(1);
  }
  strbuilder[0] = '\0';
  strncpy(strbuilder, a, m);
  for (int i = 1; i < n; ++i) {
    if (!strncmp(a + (i - 1) * m, a + i * m, m)) {
      strcat(strbuilder, "*");
    } else {
      strcat(strbuilder, " ");
      strncat(strbuilder, a + i * m, m);
    }
  }
  printf("%s\n", strbuilder);
  free(strbuilder);
  free(a);
}

void bubblesort(void *a, int n, int m, int (*cmp)(const void *, const void *)) {
  void *tmp = malloc(m * sizeof(char));
  if(!tmp) exit(EXIT_FAILURE);
  for (int i = n; i > 1; --i) {
    for (int j = 0; j < i - 1; ++j) {
      void *str1 = ((char *)a) + j * m;
      void *str2 = ((char *)a) + (j + 1) * m;
      if (cmp(str1, str2) > 0) {
        memcpy(tmp, str2, m);
        memcpy(str2, str1, m);
        memcpy(str1, tmp, m);
      }
    }
  }
  free(tmp);
}
