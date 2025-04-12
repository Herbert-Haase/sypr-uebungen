#include <stdalign.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define VAR_NAME(x) #x

int main(void) {
  signed char sch = 1;
  printf("Adresse: %p ", (void *)&sch);
  printf("Platzbedarf: %zu ", sizeof sch);
  printf("Alignment: %lu ", alignof sch);
  printf("Typ: signed character ");
  printf("Name: %s ", VAR_NAME(sch));
  printf("Wert: %hhd\n", sch);

  char ch = 'c';
  printf("Adresse: %p ", (void *)&ch);
  printf("Platzbedarf: %zu ", sizeof ch);
  printf("Alignment: %lu ", alignof ch);
  printf("Typ: character ");
  printf("Name: %s ", VAR_NAME(ch));
  printf("Wert: %c\n", ch);

  unsigned char uch = 10;
  printf("Adresse: %p ", (void *)&uch);
  printf("Platzbedarf: %zu ", sizeof uch);
  printf("Alignment: %lu ", alignof uch);
  printf("Typ: unsigned charcter ");
  printf("Name: %s ", VAR_NAME(uch));
  printf("Wert: %hhu\n", uch);

  short shrt = 2;
  printf("Adresse: %p ", (void *)&shrt);
  printf("Platzbedarf: %zu ", sizeof shrt);
  printf("Alignment: %lu ", alignof shrt);
  printf("Typ: Short ");
  printf("Name: %s ", VAR_NAME(shrt));
  printf("Wert: %hd\n", shrt);

  int i = 3;
  printf("Adresse: %p ", (void *)&i);
  printf("Platzbedarf: %zu ", sizeof i);
  printf("Alignment: %lu ", alignof i);
  printf("Typ: integer ");
  printf("Name: %s ", VAR_NAME(i));
  printf("Wert: %i\n", i);

  long l = 4L;
  printf("Adresse: %p ", (void *)&l);
  printf("Platzbedarf: %zu ", sizeof l);
  printf("Alignment: %lu ", alignof l);
  printf("Typ: long Integer ");
  printf("Name: %s ", VAR_NAME(l));
  printf("Wert: %li\n", l);

  long long ll = 5LL;
  printf("Adresse: %p ", (void *)&ll);
  printf("Platzbedarf: %zu ", sizeof ll);
  printf("Alignment: %lu ", alignof ll);
  printf("Typ: long long Integer ");
  printf("Name: %s ", VAR_NAME(ll));
  printf("Wert: %lli\n", ll);

  unsigned short ushort = 7U;
  printf("Adresse: %p ", (void *)&ushort);
  printf("Platzbedarf: %zu ", sizeof ushort);
  printf("Alignment: %lu ", alignof ushort);
  printf("Typ: unsigned short Integer ");
  printf("Name: %s ", VAR_NAME(ushort));
  printf("Wert: %hu\n", ushort);

  unsigned int ui = 8U;
  printf("Adresse: %p ", (void *)&ui);
  printf("Platzbedarf: %zu ", sizeof ui);
  printf("Alignment: %lu ", alignof ui);
  printf("Typ: unsigned Integer ");
  printf("Name: %s ", VAR_NAME(ui));
  printf("Wert: %ui\n", ui);

  unsigned long ul = 9UL;
  printf("Adresse: %p ", (void*) &ul);
  printf("Platzbedarf: %zu ", sizeof ul);
  printf("Alignment: %lu ", alignof ul);
  printf("Typ: unsigned long Integer ");
  printf("Name: %s ", VAR_NAME(ul));
  printf("Wert: %lu\n", ul);

  unsigned long long ull = 10ULL;
  printf("Adresse: %p ", (void*) &ull);
  printf("Platzbedarf: %zu ", sizeof ull);
  printf("Alignment: %lu ", alignof ull);
  printf("Typ: unsigned long long Integer ");
  printf("Name: %s ", VAR_NAME(ull));
  printf("Wert: %llu\n", ull);

  float f = 11.0f;
  printf("Adresse: %p ", (void*) &f);
  printf("Platzbedarf: %zu ", sizeof f);
  printf("Alignment: %lu ", alignof f);
  printf("Typ: float ");
  printf("Name: %s ", VAR_NAME(f));
  printf("Wert: %f\n", f);

  double d = 12.0;
  printf("Adresse: %p ", (void*) &d);
  printf("Platzbedarf: %zu ", sizeof d);
  printf("Alignment: %lu ", alignof d);
  printf("Typ: double ");
  printf("Name: %s ", VAR_NAME(d));
  printf("Wert: %f\n", d);

  long double uld = 13.0L;
  printf("Adresse: %p ", (void*) &uld);
  printf("Platzbedarf: %zu ", sizeof uld);
  printf("Alignment: %lu ", alignof uld);
  printf("Typ: long double ");
  printf("Name: %s ", VAR_NAME(uld));
  printf("Wert: %Lf\n", uld);

  bool ja = 15;
  printf("Adresse: %p ", (void*) &ja);
  printf("Platzbedarf: %zu ", sizeof ja);
  printf("Alignment: %lu ", alignof ja);
  printf("Typ: boolean ");
  printf("Name: %s ", VAR_NAME(ja));
  printf("Wert: true\n");

  const char *s = "Hallo";
  printf("Adresse: %p ", (void*) &s);
  printf("Platzbedarf: %zu ", sizeof s);
  printf("Alignment: %lu ", alignof s);
  printf("Typ: charcter pointer ");
  printf("Name: %s ", VAR_NAME(s));
  printf("Wert: %s\n", s);

  if (sizeof(int) == 4 && sizeof(long int) == 4 && sizeof(char *) == 4)
    printf("ILP32\n");
  if (sizeof(int) == 4 && sizeof(long int) == 8 && sizeof(char *) == 8)
    printf("LP64\n");
  if (sizeof(int) == 4 && sizeof(long int) == 4 && sizeof(long long int) == 8 &&
      sizeof(char *) == 8)
    printf("LLP64\n");

  return 0;
}
