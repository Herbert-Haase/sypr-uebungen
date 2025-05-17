/*
 * grusstest.cpp
 *
 * Autor: H.Drachenfels
 * Erstellt am: 16.5.2024
 */
#include "gruss.h"
#include "systemuhr.h"
#include "testuhr.h"
#include <iostream>

int main()
{
    try
    {
        systemuhr s;
        gruss g(&s);

        std::cout << g.gruessen() << std::endl;
        // systemuhr ss = s; // kein Copy-Konstruktor

        testuhr t; // Mock-Objekt
        gruss h(&t);

        unsigned stunde, minute;
        while (std::cin >> stunde >> minute)
        {
            t.stellen(stunde, minute);
            std::cout << h.gruessen() << std::endl;
        }

        //testuhr tt;
        //tt = t; // kein operator=
    }
    catch (std::string &s)
    {
        std::cerr << s << std::endl;
    }
}

