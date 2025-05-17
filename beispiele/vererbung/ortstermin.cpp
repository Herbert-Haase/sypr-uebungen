/*
 * ortstermin.cpp
 *
 * Beispielprogramm Vererbung.
 *
 * Autor: H.Drachenfels
 * Erstellt am: 16.5.2024
 */
#include "ortstermin.h"
#include <stdexcept>

ortstermin::ortstermin(const std::string &wo, const datum &wann, const std::string &was)
: termin(wann, was), wo(wo)
{
	if (wo.empty())
	{
		throw std::invalid_argument("ungueltiger Termin");
	}
}

std::string ortstermin::get_ort() const
{
    return this->wo;
}

