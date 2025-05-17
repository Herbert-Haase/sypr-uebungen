/*
 * termin.cpp
 *
 * Beispielprogramm Klasse.
 *
 * Autor: H.Drachenfels
 * Erstellt am: 16.5.2024
 */
#include "termin.h"

termin::termin(const datum &wann, const std::string &was)
: wann(wann), was(was)
{ }

void termin::verschieben(const datum &wann)
{
    this->wann = wann;
}

datum termin::get_datum() const
{
    return this->wann;
}

std::string termin::get_beschreibung() const
{
    return this->was;
}

