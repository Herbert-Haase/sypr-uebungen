/*
 * ortstermintest.cpp
 *
 * Beispielprogramm Vererbung.
 *
 * Autor: H.Drachenfels
 * Erstellt am: 10.2.2021
 */
#include "ortstermin.h"
#include <iostream>

int main()
{
    ortstermin ot{"G151", {11, 10, 2016}, "Uebung"};
    ot.verschieben(datum::heute());
    std::cout << ot.get_ort() << ", "
              << ot.get_datum() << ", "
              << ot.get_beschreibung() << std::endl;

    const termin& t = ot; // Referenzen sind polymorph
    // t.verschieben({11, 11, 1111}); // wegen const nicht aufrufbar
    std::cout // << t.get_ort() << ", " // fehlt in der Basisklasse
              << t.get_datum() << ", "
              << t.get_beschreibung() << std::endl;

    // ortstermin ot_copied = ot; // kein Copy-Konstruktor
    // ortstermin ot_moved = std::move(ot); // keine Move-Konstruktor
}

