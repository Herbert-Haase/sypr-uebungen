/*
 * systemuhr.h
 *
 * Autor: H.Drachenfels
 * Erstellt am: 12.8.2020
 */

#ifndef SYSTEMUHR_H
#define SYSTEMUHR_H

#include "uhr.h"

class systemuhr final : public uhr
{
public:
    virtual void ablesen(unsigned& s, unsigned& m) const override;
};

#endif

