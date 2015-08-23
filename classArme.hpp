#ifndef CLASSARME_HPP_INCLUDED
#define CLASSARME_HPP_INCLUDED

#include <iostream>
#include <string>

class Arme
{
public:
    Arme();
    Arme(std::string prenom, std::string texture, short degats, short prix);

    std::string getPrenom()const {return m_prenom;}
    std::string getTexture()const {return m_texture;}
    short getDegats()const {return m_degats;}
    short getPrix()const {return m_prix;}

    void information()const;



private:
    std::string m_prenom;
    std::string m_texture;
    short m_degats;
    short m_prix;

};


#endif // CLASSARME_HPP_INCLUDED
