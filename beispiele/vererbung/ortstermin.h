/*
 * ortstermin.h
 *
 * Beispielprogramm Vererbung.
 *
 * Autor: H.Drachenfels
 * Erstellt am: 10.2.2021
 */
#ifndef ORTSTERMIN_H
#define ORTSTERMIN_H

#include "termin.h"
#include <string>

class ortstermin final : public termin
{
private:
    std::string wo;
public:
    ortstermin(const std::string&, const datum&, const std::string&);
    // ~ortstermin() = default;
    // ortstermin(const ortstermin&) = delete;
    // ortstermin& operator=(const ortstermin&) = delete;
    // ortstermin(ortstermin&&) = delete;
    // ortstermin& operator=(ortstermin&&) = delete;
    std::string get_ort() const;
};

#endif

