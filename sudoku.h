#ifndef SUDOKU_H
#define SUDOKU_H

#include <QVector>
#include <QRandomGenerator>
#include <QDebug>
#include <QFile>

#include "cellule.h"

class Sudoku
{
public:
    Sudoku(int taille_grille);
    int dimension;
    int caractere_max;
    QVector<int> liste_caracter_possible;
    QVector<QVector<Cellule>> grille;

    QVector<Cellule*> liste_pointeur_cellule_contrainte(int x, int y);


//    QVector<int> liste_valeur_impossible_ligne(int x, int y);
//    QVector<int> liste_valeur_impossible_colonne(int x, int y);
//    QVector<int> liste_valeur_impossible_carre(int x, int y);
//    QVector<int> liste_valeur_possible_cellule(int x, int y);
//    void placer_valeur(int x, int y);
    void copie_sudoku(Sudoku* sudoku);
};

bool initialisation_aleatoire(Sudoku* sudoku_cible, double pourcentage_remplissage);
//void creation_sudoku_possibilités(Sudoku* sudoku);
bool resolution_sudoku_csp_init(Sudoku* sudoku, Sudoku* sudoku_solution);
Sudoku sudoku_remplissage_fichier(QString nom_fichier);

#endif // SUDOKU_H
