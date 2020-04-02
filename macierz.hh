#include "Wektor.hh"

#ifndef _MACIERZ_HH
#define _MACIERZ_HH

#include "Wektor.hh"

class macierz
{
    Wektor tab[ROZMIAR];
public:
    macierz();
    macierz(const macierz &);
    macierz(Wektor, Wektor, Wektor);
    const Wektor &operator [] (const int&) const;
    Wektor &operator [] (const int&);
};

std::ostream &operator << (std::ostream &, const macierz&);
std::istream &operator >> (std::istream &, macierz &);
#endif