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

  srand((unsigned)time(NULL));
  for (int i = 0; i < n; ++i) {
    int r = rand() % n;
    a[i] = r;
  }
}
