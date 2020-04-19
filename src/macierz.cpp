#include "macierz.hh"

macierz::macierz()
{
    for(int i(0); i < ROZMIAR; i++)
    {
        for(int j(0); j < ROZMIAR; j++)
        {
            this->tab[i][j] = 0;
        }
    } 
}

macierz::macierz(const Wektor tab[])
{
    for(int i(0); i < ROZMIAR; i++)
    {
        this->tab[i] = tab[i];
    } 
}

macierz::macierz(Wektor A, Wektor B, Wektor C)
{
        this->tab[0] = A;
        this->tab[1] = B;
        this->tab[2] = C;
    
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
        strm << Arg1[i];
        if(i != ROZMIAR - 1)
        {
            strm << std::endl;
        }
    }

    return strm;
}

std::istream &operator >> (std::istream &strm, macierz &Arg1)
{
    for(int i(0); i < ROZMIAR; i++)
    {
        strm >> Arg1[i];
    }

    return strm;
}

macierz macierz::operator + (const macierz &Arg1) const
{   
    macierz wynik;
    for(int i(0); i < ROZMIAR; i++)
    {
        wynik[i] = this->tab[i] + Arg1[i];
    }
    return wynik;
}

macierz macierz::operator - (const macierz &Arg1) const
{   
    macierz wynik;
    for(int i(0); i < ROZMIAR; i++)
    {
        wynik[i] = this->tab[i] - Arg1[i];
    }

    return wynik;
}

macierz macierz::operator * (const macierz &Arg1) const
{
    macierz wynik;
    for(int i(0); i < ROZMIAR; i++)
    {
        for(int j(0); j < ROZMIAR; j++)
        {
            double suma = 0;;
            for(int k(0); k < ROZMIAR; k++)
            { suma += this->tab[i][k] * Arg1[k][j]; }
            wynik[i][j] = suma;
        }
    }
    return wynik;
}

macierz macierz::operator * (const double &liczba) const
{
    macierz wynik;
    for(int i(0); i < ROZMIAR; i++)
    {
        wynik[i] = this->tab[i] * liczba;
    }

    return wynik;
}

Wektor macierz::operator * (const Wektor & Arg1) const
{
    Wektor wynik;
    for(int i(0); i < ROZMIAR; i++)
    {
        double suma = 0;
        for(int j(0); j < ROZMIAR; j++)
        {
            suma += this->tab[i][j] * Arg1[j];
        }
        wynik[i] = suma;
    }
    
    return wynik;
}

void macierz::transponuj()
{   
    macierz tmp(*this);
    for(int i(0); i < ROZMIAR; i++)
    {
        for(int j(0); j < ROZMIAR; j++)
        {
            this->tab[j][i] = tmp[i][j];
        }
    }
}

double macierz::wyznacznik(const metoda_wyznacznika &metoda) const
{
    switch(metoda)
    {
        case m_gauss:
            return gauss(*this);
            break;
        case m_sarrus:
            return sarrus(*this);
            break;
        case m_la_place:
            //return la_place(*this);
            break;
    }

    return 0;
}