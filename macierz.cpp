#include "macierz.hh"

macierz::macierz()
{}

macierz::macierz(const macierz& Arg1)
{
    for(int i(0); i < ROZMIAR; i++)
    {
        for(int j(0); j < ROZMIAR; j++)
        {
            this->tab[i][j] = 0;
        }
    }
}

macierz::macierz(Wektor x, Wektor y, Wektor z)
{
    for(int i(0); i < ROZMIAR; i++)
    {
            this->tab[i][0] = x[i];
            this->tab[i][1] = y[i];
            this->tab[i][2] = z[i];
    }
}

const Wektor &macierz::operator[](const int &index1) const
{
    if(index1 < 0 && index1 > ROZMIAR)
    {
        std::cerr << "Zly indeks!" << std::endl;
        exit(1);
    }

    return tab[index1];
}

Wektor &macierz::operator[](const int &index1)
{
    if(index1 < 0 && index1 > ROZMIAR)
    {
        std::cerr << "Zly indeks!" << std::endl;
        exit(1);
    }

    return tab[index1];
}

std::ostream &operator << (std::ostream &strm, const macierz &Arg1)
{
    for(int i(0); i < ROZMIAR; i++)
    {
        for(int j(0); j < ROZMIAR; j++)
        {
            strm << Arg1[i][j] << " ";
        }
        strm << std::endl;
    }

    return strm;
}

std::istream &operator >> (std::istream &strm, macierz &Arg1)
{
    for(int i(0); i < ROZMIAR; i++)
    {
        for(int j(0); j < ROZMIAR; j++)
        {
            strm >> Arg1[i][j];
        }
    }

    return strm;
}