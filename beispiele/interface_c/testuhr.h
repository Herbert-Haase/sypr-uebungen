/*
 * testuhr.h
 *
 * Autor: H.Drachenfels
 * Erstellt am: 20.1.2018
 */

#ifndef TESTUHR_H
#define TESTUHR_H

#include "uhr.h"

uhr *new_testuhr();
void testuhr_stellen(uhr * const u, unsigned s, unsigned m);

#endif

