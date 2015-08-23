#ifndef CLASSPERSONNAGE_HPP_INCLUDED
#define CLASSPERSONNAGE_HPP_INCLUDED

#include <iostream>
#include <string>
#include <fstream>

#include "messages.hpp"
#include "classArme.hpp"
#include "classArmure.hpp"

class Personnage
{
public:
    Personnage();
    Personnage(std::string prenom, short vie, short argent, short potionVie, Arme const& arme, Armure const& armure); //manque armure
    ~Personnage();

    void attaquer(Personnage &cible);
    void recevoirDegats(short degats);
    void acheterArme(Arme const& arme);
    void vendreArme();

    void acheterArmure(Armure const& armure);
    void vendreArmure();


    bool estVivant()const;

    bool sauvegarder()const;

    void information()const;

    void boirePotionVie();
    void acheterPotionVie();



protected:
    std::string m_prenom;
    short m_vie;
    short m_argent;
    short m_potionVie;

    Arme *m_arme;
    Armure *m_armure;


};


#endif // CLASSPERSONNAGE_HPP_INCLUDED
