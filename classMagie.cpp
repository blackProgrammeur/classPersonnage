#include "classMagie.hpp"

Magie::Magie()
: m_prenom("default"), m_type("default"), m_degats(0), m_coutMana(0), m_prix(0)
{

}


Magie::Magie(std::string prenom, std::string type, short degats, short coutMana, short prix)
: m_prenom(prenom), m_type(type), m_degats(degats), m_coutMana(coutMana), m_prix(prix)
{

}

void Magie::information()const
{
    std::cout << std::endl << "MAGIE" << std::endl;
    std::cout << "prenom\t: " << m_prenom << std::endl;
    std::cout << "type\t: " << m_type << std::endl;
    std::cout << "degats\t: " << m_degats << std::endl;
    std::cout << "cout mana\t: " << m_coutMana << std::endl;
    std::cout << "prix\t: " << m_prix << std::endl;
}
