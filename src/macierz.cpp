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
        strm << Arg1[i] << std::endl;
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

double macierz::wyznacznik()
{
    double liczba = 0;
    macierz tmp(*this);

    for(int i(0); i < ROZMIAR; i++)
    {
        if(tmp[0][0] != 0)
        {break; }
        
        std::swap(tmp[0], tmp[i]);
    }

    if(tmp[0][0] == 0)
    {
        return 0;
    }
    
    for(int i(1); i < ROZMIAR; i++)
    {   
        if(tmp[0][0] == 0)
        {liczba = 0; }
        else 
        {tmp[i] = tmp[i] - (tmp[0] * (tmp[i][0] / tmp[0][0])); }
    }
    
    for(int i(2); i < ROZMIAR; i++)
    {
        for(int j(1); j < ROZMIAR-1; j++)
        {   
            if(tmp[i-1][j] == 0)
            {liczba = 0; }
            else 
            {
                tmp[i] = tmp[i] - (tmp[i-1] * (tmp[i][j] / tmp[i-1][j]));
            }
        }
   }

   liczba = 1;
   for(int i(0); i < ROZMIAR; i++)
   {
      liczba = liczba * tmp[i][i];
   }

   return liczba;
}

void macierz::odwroc()
{
    
}