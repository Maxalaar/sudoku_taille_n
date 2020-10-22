#ifndef CELLULE_H
#define CELLULE_H

#include <QVector>

class Cellule
{
public:
    Cellule();
    int valeur_fix = -1;
    int position_x;
    int position_y;
    QVector<int> liste_valeur_possible;
    QVector<Cellule*> liste_cellule_contrainte;
    void init(int position_x, int position_y, QVector<int> liste_valeur_possible, QVector<Cellule*> liste_cellule_contrainte);
    void placer_valeur(int valeur);
};

#endif // CELLULE_H
