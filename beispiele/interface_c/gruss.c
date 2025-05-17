/*
 * gruss.c
 *
 * Autor: H.Drachenfels
 * Erstellt am: 25.7.2018
 */

#include "gruss.h"
#include <stddef.h>

const char *gruessen(uhr *u)
{
    unsigned stunde;

    uhr_ablesen(u, &stunde, NULL); // dynamische Bindung

    if (6 <= stunde && stunde < 11)
    {
        return "Guten Morgen";
    }

    if (11 <= stunde && stunde < 18)
    {
        return "Guten Tag";
    }

    if (18 <= stunde && stunde <= 23)
    {
        return "Guten Abend";
    }

    return "Nachtruhe!";
}

