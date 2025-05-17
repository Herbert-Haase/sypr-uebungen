/*
 * uhr.h
 *
 * Autor: H.Drachenfels
 * Erstellt am: 20.1.2018
 */

#ifndef UHR_H
#define UHR_H

typedef struct interface_uhr uhr;

void uhr_destruct(uhr * const u);
void uhr_ablesen(const uhr * const u, unsigned *s, unsigned *m);

#endif

