/*
 * termin.h
 *
 * Beispielprogramm Vererbung.
 *
 * Autor: H.Drachenfels
 * Erstellt am: 10.2.2021
 */
#ifndef TERMIN_H
#define TERMIN_H

#include "datum.h"
#include <string>

class termin // Oberklasse: ohne final
{
private:
    datum wann;
    std::string was;
public:
    termin(const datum&, const std::string&);
    virtual ~termin() = default; // Oberklasse: dynamische Bindung

    // Entity-Klasse: keine Copy-Move-Semantik
    termin(const termin&) = delete;
    termin& operator=(const termin&) = delete;
    termin(termin&&) = delete;
    termin& operator=(termin&&) = delete;

    void verschieben(const datum&);
    datum get_datum() const;
    std::string get_beschreibung() const;
};

#endif

