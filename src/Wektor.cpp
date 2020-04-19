#include "Wektor.hh"

Wektor::Wektor()
{
    for(int i(0); i < ROZMIAR; i++)
    {
        this->tab[i] = 0;
    }
}

Wektor::Wektor(double x, double y, double z)
{   
    tab[0] = x;
    tab[1] = y;
    tab[2] = z;
}

Wektor::Wektor(const double tab[])
{   
    for(int i(0); i < ROZMIAR; i++)
    {
        this->tab[i] = tab[i];
    }
}

Wektor Wektor::operator + (const Wektor &Arg1) const
{
    Wektor wynik;
    for(int i(0); i < ROZMIAR; i++)
    {
       wynik[i] = this->tab[i] + Arg1[i];
    }  
    return wynik;
}

Wektor Wektor::operator - (const Wektor &Arg1) const
{
    Wektor wynik;
    for(int i(0); i < ROZMIAR; i++)
    {
        wynik[i] = this->tab[i] - Arg1[i];
    }  
    return wynik;
}

double Wektor::operator * (const Wektor &Arg1) const
{
    double wynik = 0;
    for(int i(0); i < ROZMIAR; i++)
    {
        wynik += (this->tab[i] * Arg1[i]);
    }
    return wynik;
}

Wektor Wektor::operator * (const double &liczba) const
{
    Wektor wynik;
    for(int i(0); i < ROZMIAR; i++)
    {
        wynik[i] = this->tab[i] * liczba;
    }
    return wynik;
}

Wektor Wektor::operator / (const double &liczba) const
{
    Wektor wynik;
    if(liczba == 0)
    {
        std::cerr << "Dzielenie przez zero!" << std::endl;
        exit(1);
    }else 
    {
        for(int i(0); i < ROZMIAR; i++)
        {
            wynik[i] = this->tab[i] / liczba;
        }
    }

    return wynik;
}

bool Wektor::operator == (const Wektor &Arg1) const
{
    for(int i(0); i < ROZMIAR; i++)
    {
        if(fabs(this->tab[i] != Arg1[i]) > FLT_EPSILON)
        {return false; }
    }

    return true;
}

bool Wektor::operator != (const Wektor &Arg1) const
{
    return !(*this == Arg1);
}

const double &Wektor::operator [] (const int &index) const
{
    if(index < 0 && index > ROZMIAR)
    {
        std::cerr << "Zly indeks!" << std::endl;
        exit(1);
    }

    return tab[index];
}

double &Wektor::operator [] (const int &index)
{
    if(index < 0 && index > ROZMIAR)
    {
        std::cerr << "Zly indeks!" << std::endl;
        exit(1);
    }

    return tab[index];
}

double Wektor::dlugosc() const
{
    return sqrt((*this) * (*this));
}

std::ostream &operator << (std::ostream &strm, const Wektor &Arg1)
{
    for(int i(0); i < ROZMIAR; i++)
    {
        strm << Arg1[i];
        if(i != ROZMIAR - 1)
        {
            strm << " ";
        }
    }
    return strm;
}

std::istream &operator >> (std::istream &strm, Wektor &Arg1)
{
    for(int i(0); i < ROZMIAR; i++)
    {
        strm >> Arg1[i];
    }

    return strm;
}