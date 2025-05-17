/*
 * testuhr.h
 *
 * Autor: H.Drachenfels
 * Erstellt am: 12.8.2020
 */

#ifndef TESTUHR_H
#define TESTUHR_H

#include "uhr.h"

class testuhr final : public uhr
{
public:
    testuhr();
    void stellen(unsigned s, unsigned m);
    virtual void ablesen(unsigned& s, unsigned& m) const override;
private:
    unsigned stunde;
    unsigned minute;
};

#endif

