/*
 * grusstest.cpp
 *
 * Autor: H.Drachenfels
 * Erstellt am: 11.12.2024
 */

#include "gruss.h"
#include "systemuhr.h"
#include "testuhr.h"
#include <iostream>

int main()
{
    try
    {
        gruss<systemuhr> g;
        std::cout << g.gruessen() << std::endl;

        gruss<testuhr> h;
        unsigned stunde, minute;
        while (std::cin >> stunde >> minute)
        {
            h.uhr.stellen(stunde, minute);
            std::cout << h.gruessen() << std::endl;
        }
    }
    catch (std::string &s)
    {
        std::cerr << s << std::endl;
    }
}

