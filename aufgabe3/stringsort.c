// stringsort.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_LEN 20

void bubblesort(int n, int m, char *a);

int main(int argc, const char *argv[]) {
  if (argc != 2) {
    printf("Aufruf: %s Anzahl\n", argv[0]);
    printf("Anzahl muss mindestens 1 sein\n");

    return EXIT_FAILURE;
  }
  int n = atoi(argv[1]);
  if (n < 1) {
    printf("Anzahl muss mindestens 1 sein\n");
    return EXIT_FAILURE;
  }
  char(*a)[NUM_LEN] = malloc(n * sizeof(char[NUM_LEN]));
  if (!a) {
    fprintf(stderr, "out of memory");
    exit(1);
  }
  srand(time(NULL));

  puts("Unsortierte Array:");

  int str_amount = 0;
  for (int i = 0; i < n; ++i) {
    int r = rand() % 10;
    str_amount += sprintf(*(a + i), "%d", r);
    printf("%s ", *(a + i));
  }
  puts("\nSorted");
  bubblesort(n, NUM_LEN, &a[0][0]);

  char *strbuilder = malloc(2 * str_amount * sizeof(char) + 1);
  if (!strbuilder) {
    fprintf(stderr, "out of memory");
    exit(1);
  }
  strcpy(strbuilder, *a);
  for (int i = 1; i < n; ++i) {
    if (!strcmp(*(a + i - 1), *(a + i))) {
      strcat(strbuilder, "*");
    } else {
      strcat(strbuilder, " ");
      strcat(strbuilder, *(a + i));
    }
  }
  printf("%s\n", strbuilder);
  free(strbuilder);
  free(a);
}

void bubblesort(int n, int m, char *a) {
  char tmp[NUM_LEN];
  for (int i = n; i > 1; --i) {
    for (int j = 0; j < (i - 1); ++j) {
      char *str1 = a + (j * m);
      char *str2 = a + ((j + 1) * m);
      if (strcmp(str1, str2) > 0) {
        strcpy(tmp, str2);
        strcpy(str2, str1);
        strcpy(str1, tmp);
      }
    }
  }
}
