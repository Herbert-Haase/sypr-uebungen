/*
 * systemuhr.h
 *
 * Autor: H.Drachenfels
 * Erstellt am: 11.12.2024
 */

#ifndef SYSTEMUHR_H
#define SYSTEMUHR_H

class systemuhr final
{
public:
    systemuhr() = default;
    void ablesen(unsigned& s, unsigned& m) const;
    // entity: kein copy und move
    systemuhr(const systemuhr&) = delete;
    systemuhr& operator=(const systemuhr&) = delete;
    systemuhr(systemuhr&&) = delete;
    systemuhr& operator=(systemuhr&&) = delete;
};

#endif

