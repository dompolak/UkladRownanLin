#include "macierz.hh"

double macierz::gauss(macierz tmp) const
{
    double liczba = 0;
    
    for(int i(0); i < ROZMIAR; i++)
    {
        if(tmp[0][0] != 0)
        {break; }
        
        std::swap(tmp[0], tmp[i]);
    }

    if(tmp[0][0] == 0)
    {return 0; }
    
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

/*double macierz::la_place(macierz tmp, int n)
{
    if(n == 1)
    {
        return;
    }
    else 
}*/

double macierz::sarrus(macierz tmp) const
{
    return (tmp[0][0]*tmp[1][1]*tmp[2][2]+tmp[0][1]*tmp[1][2]*tmp[2][0]+tmp[0][2]*tmp[1][0]*tmp[2][1])
        -(tmp[0][2]*tmp[1][1]*tmp[2][0]+tmp[0][0]*tmp[1][2]*tmp[2][1]+tmp[0][1]*tmp[1][0]*tmp[2][2]);
}