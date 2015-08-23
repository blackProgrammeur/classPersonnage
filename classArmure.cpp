#include "classArmure.hpp"

Armure::Armure()
: m_prenom("default"), m_texture("default"), m_defense(0), m_prix(0)
{

}

Armure::Armure(std::string prenom, std::string texture, short defense, short prix)
: m_prenom(prenom), m_texture(texture), m_defense(defense), m_prix(prix)
{

}

short Armure::recevoirDegats(short degats)
{
    short temp = m_defense;
    m_defense -= degats;
    if(m_defense < 0)
    {
        m_defense = 0;
    }
    degats -= temp;
    if(degats < 0)
    {
        degats = 0;
    }
    return degats;
}


 void Armure::information()const
 {
    std::cout << std::endl << "ARMURE" << std::endl;
    std::cout << "prenom\t: " << m_prenom << std::endl;
    std::cout << "texture\t: " << m_texture << std::endl;
    std::cout << "defense\t: " << m_defense << std::endl;
    std::cout << "prix\t: " << m_prix << std::endl;
 }
