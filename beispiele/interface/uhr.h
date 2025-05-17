/*
 * uhr.h
 *
 * Autor: H.Drachenfels
 * Erstellt am: 29.4.2021
 */

#ifndef UHR_H
#define UHR_H

class uhr // interface
{
public:
    virtual ~uhr() = default;
    virtual void ablesen(unsigned& s, unsigned& m) const = 0;
    /*
     * Interfaces sind nur fuer Entities gedacht.
     * Bei Entities kein copy und move.
     */
    uhr(const uhr&) = delete;
    uhr& operator=(const uhr&) = delete;
    uhr(uhr&&) = delete;
    uhr& operator=(uhr&&) = delete;
protected:
    uhr() = default;
};

#endif

