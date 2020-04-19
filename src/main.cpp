#include "UkladRownanLin.hh"

int main()
{

uklad_rownan uklad;
Wektor we_wynikow, we_bledu;

std::cin >> uklad;
std::cout << uklad << std::endl << std::endl;

try
{
    we_wynikow = uklad.Oblicz();
    std::cout << we_wynikow << std::endl;

}
catch(std::string wyjatek)
{
    if(wyjatek == "wyjatek1")
    {
        std::cout << "Brak rozwiazan" << std::endl;
    }
    if(wyjatek == "wyjatek2")
    {
        std::cout << "Nieskonczenie wiele rozwiazan" << std::endl;
    }    
}

we_bledu = wektor_bledu(uklad, we_wynikow);
std::cout << "Wektor bledu: ( " << we_bledu << " )" << std::endl;
std::cout << "Dlugosc wektora beldu: " << we_bledu.dlugosc() << std::endl;

}   