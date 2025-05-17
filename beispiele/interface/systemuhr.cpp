/*
 * systemuhr.cpp
 *
 * Autor: H.Drachenfels
 * Erstellt am: 12.8.2020
 */

#include "systemuhr.h"
#include <ctime>

void systemuhr::ablesen(unsigned& s, unsigned& m) const
{
    std::time_t t = std::time(0);
    std::tm *lt = std::localtime(&t);
    s = lt->tm_hour;
    m = lt->tm_min;
}

