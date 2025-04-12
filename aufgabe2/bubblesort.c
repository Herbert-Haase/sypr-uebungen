#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Aufruf: java Bubblesort Anzahl");
    return 0;
  }
  int n = atoi(argv[1]);
  int a[n];

  printf("Bitte %d ganze Zahlen eingeben: ", n);
  int k = 0;
  for (int i = 0; i < (sizeof(a) / sizeof(a[0])); ++i) {
    if (scanf("%d",&a[i]) == EOF) {
      break;
    }
  }
}
