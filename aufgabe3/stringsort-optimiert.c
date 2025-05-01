// stringsort.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// int mystrcmp(const void *v1, const void *v2);
void bubblesort(void *a, int n, int m, int (*cmp)(const char *, const char *));

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
  char **a = malloc(n * m * sizeof(char));
  if (!a) {
    fprintf(stderr, "out of memory");
    exit(1);
  }
  srand(time(NULL));

  puts("Unsortierte Array:");

  int str_amount = 0;
  for (int i = 0; i < n; ++i) {
    int r = rand() % n;
    str_amount += sprintf(a[i], "%d", r);
    printf("%s ", a[i]);
  }
  puts("\nSorted");
  bubblesort((void*)a, n, m, strcmp);

  char *strbuilder = malloc(2 * str_amount * sizeof(char) + 1);
  if (!strbuilder) {
    fprintf(stderr, "out of memory");
    exit(1);
  }
  strcpy(strbuilder, *a);
  for (int i = 1; i < n; ++i) {
    if (!strcmp(a[i - 1], a[i])) {
      strcat(strbuilder, "*");
    } else {
      strcat(strbuilder, " ");
      strcat(strbuilder, a[i]);
    }
  }
  printf("%s\n", strbuilder);
  free(strbuilder);
  free(a);
}

void bubblesort(void *a, int n, int m, int (*cmp)(const char *, const char *)) {
  void *tmp = malloc(m * sizeof(char));
  for (int i = n; i > 1; --i) {
    for (int j = 0; j < i - 1; ++j) {
      void *str1 = a + j;
      void *str2 = a + j + 1;
      if (strcmp((char *)str1, (char *)str2) > 0) {
        memcpy(tmp, str2, m);
        memcpy(str2, str1, m);
        memcpy(str1, tmp, m);
      }
    }
  }
  free(tmp);
}

// int mystrcmp(const void *v1, const void *v2) {
//   return strcmp((char *)v1, (char *)v2);
// }
