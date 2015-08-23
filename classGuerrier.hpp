#ifndef CLASSGUERRIER_HPP_INCLUDED
#define CLASSGUERRIER_HPP_INCLUDED

#include <iostream>
#include <string>

#include "classPersonnage.hpp"

class Guerrier : public Personnage
{
public:
    Guerrier();
    Guerrier(std::string prenom, short vie, short argent, short potionVie, Arme const& arme, Armure const& armure);
    ~Guerrier() {/*std::cout << "Destructeur Guerrier" << std::endl;*/}

    void donnerCoupDePoing(Personnage &cible);
    void crier(Personnage &cible);

    void presentation()const;



private:


};


#endif // CLASSGUERRIER_HPP_INCLUDED
