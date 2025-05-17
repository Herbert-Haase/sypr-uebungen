/*
 * grusstest.c
 *
 * Autor: H.Drachenfels
 * Erstellt am: 25.7.2018
 */

#include "gruss.h"
#include "systemuhr.h"
#include "testuhr.h"
#include <stdio.h>

int main(void)
{
    uhr *s = new_systemuhr();
    if (!s) return 1;
    printf("%s\n", gruessen(s));

    uhr *t = new_testuhr(); // Mock-Objekt
    if (!t) return 1;

    unsigned stunde, minute;
    while (scanf("%u %u", &stunde, &minute) == 2)
    {
        testuhr_stellen(t, stunde, minute);
        printf("%s\n", gruessen(t));
    }

    uhr_destruct(t);
    uhr_destruct(s);

    return 0;
}

