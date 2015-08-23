#ifndef CLASSMAGIE_HPP_INCLUDED
#define CLASSMAGIE_HPP_INCLUDED

#include <iostream>
#include <string>

class Magie
{
public:
    Magie();
    Magie(std::string prenom, std::string type, short degats, short coutMana, short prix);

    std::string getPrenom()const {return m_prenom;}
    std::string getType()const {return m_type;}
    short getDegats()const {return m_degats;}
    short getCoutMana()const {return m_coutMana;}
    short getPrix()const {return m_prix;}

    void information()const;

private:
    std::string m_prenom;
    std::string m_type;
    short m_degats;
    short m_coutMana;
    short m_prix;


};

#endif // CLASSMAGIE_HPP_INCLUDED
