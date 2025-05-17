/*
 * systemuhr.c
 *
 * Autor: H.Drachenfels
 * Erstellt am: 20.1.2018
 */

#include "systemuhr.h"
#include "uhr_impl.h"

#include <stdlib.h>
#include <time.h>

struct systemuhr
{
    uhr interface;
};

static void destruct(uhr * const u);
static void ablesen(const uhr * const u, unsigned *s, unsigned *m);

uhr *new_systemuhr()
{
    struct systemuhr *this_p = (struct systemuhr*) malloc(sizeof (struct systemuhr));
    if (!this_p) return NULL;

    this_p->interface.destruct = destruct;
    this_p->interface.ablesen = ablesen;
    return &this_p->interface;
}

static void destruct(uhr * const u)
{
    free(u);
}

static void ablesen(const uhr * const u __attribute__((unused)), unsigned *s, unsigned *m)
{
    time_t t = time(0);
    struct tm *lt = localtime(&t);

    *s = lt->tm_hour;

    if (m)
    {
        *m = lt->tm_min;
    }
}

