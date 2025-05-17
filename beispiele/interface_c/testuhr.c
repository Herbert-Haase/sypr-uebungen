/*
 * testuhr.c
 *
 * Autor: H.Drachenfels
 * Erstellt am: 25.7.2018
 */

#include "testuhr.h"
#include "uhr_impl.h"
#include <stdlib.h>

struct testuhr
{
    uhr interface; // muss am Anfang stehen
    unsigned stunde;
    unsigned minute;
};

static void destruct(uhr * const u);
static void ablesen(const uhr * const u, unsigned *s, unsigned *m);

uhr *new_testuhr()
{
    struct testuhr *this_p = (struct testuhr*) malloc(sizeof (struct testuhr));
    if (!this_p) return NULL;

    this_p->interface.destruct = destruct;
    this_p->interface.ablesen = ablesen;

    this_p->stunde = 0;
    this_p->minute = 0;

    return &this_p->interface;
}

void testuhr_stellen(uhr * const u, unsigned s, unsigned m)
{
    struct testuhr * const this_p = (struct testuhr *) u; // Downcast
    this_p->stunde = (s + m / 60) % 24;
    this_p->minute = m % 60;
}

static void destruct(uhr * const u)
{
    free(u);
}

static void ablesen(const uhr * const u, unsigned *s, unsigned *m)
{
    const struct testuhr * const this_p = (const struct testuhr *) u; // Downcast
    *s = this_p->stunde;
    if (m) *m = this_p->minute;
}

