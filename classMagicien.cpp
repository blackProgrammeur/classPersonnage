#include "classMagicien.hpp"

Magicien::Magicien()
: Personnage(), m_mana(0), m_potionMana(0), m_magie(0)
{
    m_magie = new Magie;
}


Magicien::Magicien(std::string prenom, short vie,
short argent, short potionVie, Arme const& arme, Armure const& armure, short mana, short potionMana, Magie const&magie)
: Personnage(prenom, vie, argent, potionVie, arme, armure), m_mana(mana), m_potionMana(potionMana), m_magie(0)
{
    m_magie = new Magie(magie);
}

Magicien::~Magicien()
{
    delete m_magie;
    m_magie = 0;
}

void Magicien::presentation()const
{

    std::cout << "NOUS VECURENT DANS LES HAUTES TERRES REFOULEES DU ROYAUME DE ILGAR." << std::endl;
    std::cout << "LA, NOUS NOUS CONSACRERENT ENTIEREMENT A NOTRE FORMATION SUR LA MAGIE ET LES POTIONS." << std::endl;
    std::cout << "UNE GRANDE PARTIES DE CET APPRENTISSAGE NOUS VIENT DES ELFES QUI EURENT ENVIE DE" << std::endl;
    std::cout << "PARTAGER LEURS SAVOIRS AVEC NOUS LES MAGICIENS. NOTRE ROLE EST DE PRESERVER LA PAIX" << std::endl;
    std::cout << "ENTRE CE MONDE ET LES AUTRES, DE FACON A CE QUE NOUS NE CONNESSION PLUS DE TEL GUERRE" << std::endl;
    std::cout << R"(QUE CELLE OPPOSANT TENEBES A LUMIERE AUSSI APPELE "GUERRE DU DESESPOIR" )"<< std::endl;
    std::cout << "AUJOURD'HUI, LES TENEBRES REFONT APPARITION ET C'EST A NOUS LES MAGICIEN DE LES CHASSER" << std::endl;
    std::cout << "DE NOTRE ROYAUME POUR QUE NOUS NE RECOMMENCONS PLUS DE TEL GUERRE, MAIS C'EST BIEN PARTI POUR CELA." << std::endl;
    std::cout << "MON PRENOM EST " << m_prenom << " LE MAGICIEN ET CECI EST MON HISTOIRE." << std::endl;
}




void Magicien::acheterMagie(Magie const&magie)
{
    if(m_argent >= magie.getPrix())
    {
        delete m_magie;
        m_magie = 0;

        m_magie = new Magie(magie);
        m_argent -= magie.getPrix();
    }
    else
    {
        pasArgent();
        std::cout << "IL VOUS MANQUE : " << (magie.getPrix() - m_argent) << " D'ARGENTS" << std::endl;
    }
}


void Magicien::vendreMagie()
{
    if(confirmer())
    {
        short prixMagie = m_magie->getPrix();
        m_argent += prixMagie;


        delete m_magie;
        m_magie = 0;


        std::cout << "ATTENTION DESORMAIS VOUS N'AVEZ PLUS DE MAGIE" << std::endl;

    }
}


void Magicien::acheterPotionMana()
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

void Magicien::lancerSort(Personnage &cible)
{
    if(m_magie == 0)
    {
        std::cout << "VOUS NE POUVEZ PAS ATTAQUEZ CARVOUS N'AVEZ PLUS DE MAGIE" << std::endl;
    }
    else if(m_mana < m_magie->getCoutMana())
    {
        std::cout << "VOUS NE POUVEZ PAS LANCER UN SORT CAR VOUS N'AVEZ PLUS ASSEZ DE MANA" << std::endl;
        std::cout << "IL VOUS FAUT ENCORE " << (m_magie->getCoutMana() - m_mana) << " DE MANA" << std::endl;
    }
    else
    {
        m_mana -= m_magie->getCoutMana();
        cible.recevoirDegats(m_magie->getDegats());

    }
}

void Magicien::boirePotionMana()
{
    if(m_potionMana > 0)
    {
        m_mana += 50;
        m_potionMana -= 1;
    }
    else
    {
        aucunePotionMana();
    }
}

void Magicien::information()const
{
    Personnage::information();
    std::cout << std::endl << "AUTRE SPECIFICATION" << std::endl;
    std::cout << "mana\t: " << m_mana << std::endl;
    std::cout << "potion mana\t: " << m_potionMana << std::endl;
    if(m_magie != 0)
    {
        m_magie->information();
    }

}


