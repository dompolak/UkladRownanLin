#include "Wektor.hh"

#ifndef _MACIERZ_HH
#define _MACIERZ_HH

#include "Wektor.hh"

class macierz
{
    Wektor tab[ROZMIAR];
public:
    macierz();
    macierz(const Wektor tab[]);
    macierz(Wektor, Wektor, Wektor);
    const Wektor &operator [] (const int&) const;
    Wektor &operator [] (const int&);
    macierz operator + (const macierz &) const;
    macierz operator - (const macierz &) const;
    macierz operator * (const macierz &) const;
    macierz operator * (const double &) const;
    Wektor operator * (const Wektor &) const;
    double wyznacznik();
    void odwroc();
    void transponuj();
};

std::ostream &operator << (std::ostream &, const macierz&);
std::istream &operator >> (std::istream &, macierz &);
#endif