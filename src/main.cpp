#include "UkladRownanLin.hh"

int main()
{
    /*double tablica[ROZMIAR] = {2, 3, 4};

    Wektor wektor1(tablica);
    Wektor wektor2;
    std::cin >> wektor2;
    std::cout << wektor2 << std::endl;
    std::cout << "Dlugosc: " << wektor2.dlugosc() << std::endl;
    std::cout << "Skalarnie: " << wektor1 * wektor2 << std::endl;
    std::cout << "Mnozenie liczba: " << wektor2 * 3 << std::endl;
    std::cout << "Dzielenie przez liczbe: " << wektor2 / 2 << std::endl;
    std::cout << "dodawanie wektorow " << wektor1 + wektor2 << std::endl;
    std::cout << "odejmowanie wektorow " << wektor1 - wektor2 << std::endl;

    if(wektor1 == wektor2)
    {
        std::cout << "Sa rowne" << std::endl;
    }

    if(wektor2 != wektor1)
    {
        std::cout << "nie sa rowne" << std::endl;
    }

    std::cout << "MACIERZE MACIERZE MACIERZE" << std::endl << std::endl << std::endl;
    */
    Wektor wektor_x(5, -1, 3), wektor_y(0, 1, -2), wektor_z(4, 3, 2);
    macierz nowa1(wektor_x, wektor_y, wektor_z);
    //macierz nowa1;
    //Wektor jeden(9, 5, 5);
    //std::cin >> nowa1;
    //nowa1.transponuj();
    //Wektor jeden;
    //std::cin >> nowa1;
    std::cout << "Gauss:  " << nowa1.wyznacznik(m_gauss) << std::endl << std::endl;
    std::cout << "Sarrus: " << nowa1.wyznacznik(m_sarrus) << std::endl;
    
}   