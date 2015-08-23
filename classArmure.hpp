#ifndef CLASSARMURE_HPP_INCLUDED
#define CLASSARMURE_HPP_INCLUDED

#include <iostream>
#include <string>

class Armure
{
public:
    Armure();
    Armure(std::string prenom, std::string texture, short defense, short prix);
    ~Armure() {/*std::cout << "destructeur arme" << std::endl;*/}

    std::string getPrenom()const {return m_prenom;}
    std::string getTexture()const {return m_texture;}
    short getDefense()const {return m_defense;}
    short getPrix()const {return m_prix;}

    short recevoirDegats(short degats);
    void information()const;

private:
    std::string m_prenom;
    std::string m_texture;
    short m_defense;
    short m_prix;

};


#endif // CLASSARMURE_HPP_INCLUDED
