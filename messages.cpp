#include "messages.hpp"

void pasArgent()
{
    std::cout << "VOUS N'AVEZ PAS ASSEZ D'ARGENT ACTUELLEMENT !!!" << std::endl;
}


bool confirmer()
{
    char confirmation('a');
    while ((confirmation != 'O') && (confirmation != 'N'))
    {
        std::cout << "EST TU SUR DE VOULOIR FAIRE CELA ? [O/N] :";
        std::cin >> confirmation;
        std::cin.ignore();

        if(confirmation == 'O')
        {
            return true;
        }
        else if(confirmation == 'N')
        {
            return false;
        }
        else
        {
            choixInexistant();
        }
    }
    //par defaut retourne false
    return false;

}


void aucunePotionVie()
{
    std::cout << "VOUS N'AVEZ PLUS DE POTION DE MANA !!!" << std::endl;
}

void aucunePotionMana()
{
    std::cout << "VOUS N'AVEZ PLUS DE POTION DE MANA !!!" << std::endl;
}


void choixInexistant()
{
    std::cout << "CE CHOIX EST INEXISTANT VEUILLEZ ENTRER UN CHOIX VALABLE" << std::endl;
}
