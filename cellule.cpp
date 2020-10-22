#include "cellule.h"

Cellule::Cellule()
{

}

void Cellule::init(int position_x, int position_y, QVector<int> liste_valeur_possible, QVector<Cellule*> liste_cellule_contrainte)
{
    this->position_x = position_x;
    this->position_y = position_y;
    this->liste_valeur_possible = liste_valeur_possible;
    this->liste_cellule_contrainte = liste_cellule_contrainte;
}

void Cellule::placer_valeur(int valeur)
{
    this->valeur_fix = valeur;

    QVector<int> liste_vide;
    this->liste_valeur_possible = liste_vide;

    for(int i = 0; i < liste_cellule_contrainte.size(); i++)
    {
        for(int j = 0; j < liste_cellule_contrainte[i]->liste_valeur_possible.size(); j++)
        {
            if(valeur == liste_cellule_contrainte[i]->liste_valeur_possible[j])
            {
                liste_cellule_contrainte[i]->liste_valeur_possible.remove(j);
            }
        }
    }
}
