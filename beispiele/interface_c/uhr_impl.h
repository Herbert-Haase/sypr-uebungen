/*
 * uhr_impl.h
 *
 * Autor: H.Drachenfels
 * Erstellt am: 20.1.2018
 */

#ifndef UHR_IMPL_H
#define UHR_IMPL_H

#include "uhr.h"

struct interface_uhr
{
    void (*destruct)(uhr * const u);
    void (*ablesen)(const uhr * const u, unsigned *s, unsigned *m);
};

#endif

