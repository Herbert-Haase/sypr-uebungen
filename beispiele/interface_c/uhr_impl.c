/*
 * uhr_impl.c
 *
 * Autor: H.Drachenfels
 * Erstellt am: 20.1.2018
 */

#include "uhr_impl.h"

void uhr_destruct(uhr * const u)
{
    u->destruct(u);
}

void uhr_ablesen(const uhr * const u, unsigned *s, unsigned *m)
{
    u->ablesen(u, s, m);
}

