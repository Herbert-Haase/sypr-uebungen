/*
 * grusstest-falsch.cpp
 *
 * Autor: H.Drachenfels
 * Erstellt am: 11.12.2024
 */

#include "gruss.h"
#include <iostream>
#include <string>

int main()
{
    try
    {
        gruss<std::string> g; // falsch: std::string ist keine Uhr
        std::cout << g.gruessen() << std::endl;

        gruss<int> h; // falsch: int ist keine Uhr
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

