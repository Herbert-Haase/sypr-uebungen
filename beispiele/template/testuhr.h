/*
 * testuhr.h
 *
 * Autor: H.Drachenfels
 * Erstellt am: 11.12.2024
 */

#ifndef TESTUHR_H
#define TESTUHR_H

class testuhr final
{
public:
    testuhr();
    void stellen(unsigned s, unsigned m);
    void ablesen(unsigned& s, unsigned& m) const;
    // entity: kein copy und move
    testuhr(const testuhr&) = delete;
    testuhr& operator=(const testuhr&) = delete;
    testuhr(testuhr&&) = delete;
    testuhr& operator=(testuhr&&) = delete;
private:
    unsigned stunde;
    unsigned minute;
};

#endif

