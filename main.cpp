#include <iostream>

#include "classArme.hpp"
#include "classArmure.hpp"
#include "classGuerrier.hpp"

#include "classMagie.hpp"
#include "classMagicien.hpp"

using namespace std;

int main()
{
    Arme defaut;
    Arme bronze("bronze", "bronze", 30, 500);

    Armure defautArmure;
    Armure armureBronze("armureBronze", "bronze", 40, 600);

    Magie defautMagie;
    Magie feu("feu", "typeFeu", 30, 40, 50);

    Guerrier defautGuerrier("defautGuerrier", 400, 1000, 1, bronze, armureBronze);
    Guerrier hercule("hercule", 500, 1000, 0, bronze, armureBronze);

    Magicien magicienDefaut;
    Magicien merlin("merlin", 400, 100, 1, bronze, armureBronze, 100, 0, feu);



















    return 0;
}
