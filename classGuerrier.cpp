#include "classGuerrier.hpp"


Guerrier::Guerrier()
: Personnage()
{

}

Guerrier::Guerrier(std::string prenom, short vie, short argent, short potionVie, Arme const& arme, Armure const& armure)
: Personnage(prenom, vie, argent, potionVie, arme, armure)
{

}


void Guerrier::presentation()const
{
    std::cout << "Bonjour, je suis un guerrier tres redoutable et crain de tous" << std::endl;
    std::cout << "J'ai vecu parmis les miens dans la cour du roi. Nous nous entrenions jour et nuit" << std::endl;
    std::cout << "pour etre les meilleur des notres et etre reconnu comme les plus puissants guerrier du royaume." << std::endl;
    std::cout << "Notre mission, proteger le roi, la place du throne et le royaume contre les ennemis et les creature demoniaque." << std::endl;
    std::cout << "Retenez bien mon prenom car je ne vous le redirai pas, je suis le guerrier qui incarnera vos recits " << std::endl;
    std::cout << "Et vous fera rever la nuit. Je suis " << m_prenom << " le guerrier obscur et ceci est mon histoire." << std::endl;
}

void Guerrier::donnerCoupDePoing(Personnage &cible)
{
    cible.recevoirDegats(5);
}

void Guerrier::crier(Personnage &cible)
{
    cible.recevoirDegats(2);
}


