#include "classPersonnage.hpp"

Personnage::Personnage()
: m_prenom("default"), m_vie(0), m_argent(0), m_potionVie(0), m_arme(0), m_armure(0)
{
    m_arme = new Arme;
    m_armure = new Armure;
}

Personnage::Personnage(std::string prenom, short vie, short argent, short potionVie, Arme const& arme, Armure const& armure)
: m_prenom(prenom), m_vie(vie), m_argent(argent), m_potionVie(potionVie), m_arme(0), m_armure(0)
{
    m_arme = new Arme(arme); //declare une nouvelle arme avec l'argument arme
    m_armure = new Armure(armure);

}

Personnage::~Personnage()
{
    delete m_arme;
    m_arme = 0;

    delete m_armure;
    m_armure = 0;

   // std::cout << "Destructeur Perso" << std::endl;
}

void Personnage::attaquer(Personnage &cible)
{
    if(m_arme == 0)
    {
        std::cout << "VOUS NE POUVEZ PAS ATTAQUER CAR VOUS N'AVEZ PLUS D'ARME" <<std::endl;
    }
    else
    {
        cible.recevoirDegats(m_arme->getDegats());
    }

}

void Personnage::recevoirDegats(short degats)
{

    m_vie -= m_armure->recevoirDegats(degats);


    if(m_vie < 0)
    {
        m_vie = 0; //interdiction de dépasser 0
        estVivant();    //si la vie est a zero alos appel fonction estVivant
    }
}

bool Personnage::estVivant()const
{
    return !(m_vie == 0);
    /*
        retourne true si il est vivant
    */
}

void Personnage::acheterArme(Arme const& arme)
{
    if(m_argent >= arme.getPrix())
    {
        delete m_arme;
        m_arme = 0;

        m_arme = new Arme(arme);
        m_argent -= arme.getPrix();
    }
    else
    {
        pasArgent();
        std::cout << "IL VOUS MANQUE : " << (arme.getPrix() - m_argent) << " D'ARGENTS" << std::endl;
    }
}

void Personnage::vendreArme()
{
    if(confirmer())
    {
        short prixArme = m_arme->getPrix();
        m_argent += prixArme;


        delete m_arme;
        m_arme = 0;

        std::cout << "VOUS VENEZ DE RECEVOIR " << prixArme  << std::endl;
        std::cout << "ATTENTION DESORMAIS VOUS N'AVEZ PLUS D'ARME" << std::endl;

    }
}

void Personnage::acheterArmure(Armure const& armure)
{
    if(m_argent >= armure.getPrix())
    {
        delete m_armure;
        m_armure = 0;

        m_armure = new Armure(armure);
        m_argent -= armure.getPrix();
    }
    else
    {
        pasArgent();
        std::cout << "IL VOUS MANQUE : " << (armure.getPrix() - m_argent) << " D'ARGENTS" << std::endl;
    }
}

void Personnage::vendreArmure()
{

    if(confirmer())
    {
        short prixArmure = m_armure->getPrix();
        m_argent += prixArmure;


        delete m_armure;
        m_armure = 0;

        std::cout << "VOUS VENEZ DE RECEVOIR " << prixArmure  << std::endl;
        std::cout << "ATTENTION DESORMAIS VOUS N'AVEZ PLUS D'ARMURE" << std::endl;

    }
}







bool Personnage::sauvegarder()const
{
    const std::string nomFichier("sauvegarde/sauvegarde.txt");
    std::ofstream fluxEcriture(nomFichier.c_str());

    if(fluxEcriture)
    {
        fluxEcriture << m_prenom << std::endl;
        fluxEcriture << m_vie << std::endl;
        fluxEcriture << m_argent << std::endl;
        fluxEcriture << m_potionVie << std::endl << std::endl;
        if(m_arme != 0)
        {

            fluxEcriture << "ARME" << std::endl;
            fluxEcriture << m_arme->getPrenom() << std::endl;
            fluxEcriture << m_arme->getTexture() << std::endl;
            fluxEcriture << m_arme->getDegats() << std::endl;
            fluxEcriture << m_arme->getPrix() << std::endl;
        }

        if(m_armure != 0)
        {

            fluxEcriture << "ARME" << std::endl;
            fluxEcriture << m_armure->getPrenom() << std::endl;
            fluxEcriture << m_armure->getTexture() << std::endl;
            fluxEcriture << m_armure->getDefense() << std::endl;
            fluxEcriture << m_armure->getPrix() << std::endl;
        }

        return true;
    }

    return false;
}


void Personnage::information()const
{
    std::cout << "*********************************" << std::endl;
    std::cout << "prenom\t: " << m_prenom << std::endl;
    std::cout << "vie\t: " << m_vie << std::endl;
    std::cout << "argent\t: " << m_argent << std::endl;
    std::cout << "potion vie\t: " << m_potionVie << std::endl;
    if(m_arme != 0)
    {
        m_arme->information();
    }
    if(m_armure != 0)
    {
         m_armure->information();
    }
    std::cout << "*********************************" << std::endl;
}


void Personnage::boirePotionVie()
{

    if(m_potionVie > 0)
    {
        m_vie += 50;
        m_potionVie -= 1;
    }
    else
    {
        aucunePotionVie();
    }
}


 void Personnage::acheterPotionVie()
 {
     if(m_argent >= 500)
     {
         m_argent -= 500;
         m_potionVie++;
     }
     else
     {
         pasArgent();
         std::cout << "IL VOUS MANQUE ENCORE " << (500 - m_argent) << " D'ARGENTS" << std::endl;
     }
 }
