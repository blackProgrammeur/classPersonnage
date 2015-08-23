#include "classArme.hpp"

Arme::Arme()
: m_prenom("default"), m_texture("default"), m_degats(0), m_prix(0)
{

}

Arme::Arme(std::string prenom, std::string texture, short degats, short prix)
: m_prenom(prenom), m_texture(texture), m_degats(degats), m_prix(prix)
{

}

void Arme::information()const
{
    std::cout << std::endl << "ARME" << std::endl;
    std::cout << "prenom\t: " << m_prenom << std::endl;
    std::cout << "texture\t: " << m_texture << std::endl;
    std::cout << "degats\t: " << m_degats << std::endl;
    std::cout << "prix\t: " << m_prix << std::endl;
}
