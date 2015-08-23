#ifndef CLASSMAGICIEN_HPP_INCLUDED
#define CLASSMAGICIEN_HPP_INCLUDED

#include <iostream>
#include <string>
#include "classMagie.hpp"
#include "classPersonnage.hpp"

class Magicien : public Personnage
{
public:

    Magicien();
    Magicien(std::string prenom, short vie, short argent, short potionVie, Arme const& arme, Armure const& armure, short mana, short potionMana, Magie const&magie);
    ~Magicien();

    void acheterMagie(Magie const&magie);
    void vendreMagie();
    void acheterPotionMana();

    void presentation()const;

    void lancerSort(Personnage &cible);
    void boirePotionMana();

    void information()const;

private:
    short m_mana;
    short m_potionMana;

    Magie *m_magie;
};


#endif // CLASSMAGICIEN_HPP_INCLUDED
