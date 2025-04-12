#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char *argv[]) {
  if (argc != 2) {
    printf("Aufruf: %s Anzahl", argv[0]);
    return 0;
  }

  int n = atoi(argv[1]);
  if (n <= 0) {
    fputs("Invalid number of elements.\n", stderr);
    return 1;
  }

  int *a = malloc((size_t)n * sizeof(int));
  if (!a) {
    fprintf(stderr, "Out of memory: %s at %d\n", __FILE__, __LINE__);
    return 12;
  }

  printf("Bitte %d ganze Zahlen eingeben: ", n);
  int *p = a;
  for (; p < a + n; ++p) {
    if (scanf("%d", p) == EOF)
      break;
  }

  srand((unsigned)time(NULL));
  for (; p < a + n; ++p) {
    *p = rand();
    printf("%d\n", *p);
  }

  for (int *end = a + n; end - a > 1; --end) {
    for (int *j = a; j < end - 1; ++j) {
      if (*j > *(j + 1)) {
        int tmp = *(j + 1);
        *(j + 1) = *j;
        *j = tmp;
      }
    }
  }

  puts("Sortierte Zahlenfolge: ");
  for (int *q = a; q < a + n; ++q)
    printf("%d\n", *q);

  free(a);
  return 0;
}
