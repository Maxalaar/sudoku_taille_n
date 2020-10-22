#include "main_window_sudoku.h"

#include <QApplication>
#include <QDebug>

#include "sudoku.h"
#include "affichage_sudoku.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Sudoku* sudoku;
//    sudoku = new Sudoku(2);
    Sudoku sudoku_temp = sudoku_remplissage_fichier("sudoku_2.txt");
    sudoku = &(sudoku_temp);
//    initialisation_aleatoire(sudoku, 0.35);

//    sudoku->grille[0][0].placer_valeur(2);
//    sudoku.grille[3][3].placer_valeur(4);

//    qDebug() << sudoku.grille[3][0].liste_valeur_possible;

    Affichage_sudoku* affichage_sudoku = new Affichage_sudoku(sudoku);


    Sudoku* sudoku_prov = new Sudoku(sudoku->dimension);
    sudoku_prov->copie_sudoku(sudoku);

    Sudoku* sudoku_solution = new Sudoku(sudoku->dimension);

//    creation_sudoku_possibilités(&sudoku_prov);
    bool sudoku_fini = resolution_sudoku_csp_init(sudoku_prov, sudoku_solution);

//    sudoku_solution->grille[0][0].push_back(1);

    Affichage_sudoku* affichage_sudoku_solution = new Affichage_sudoku(sudoku_solution);

    affichage_sudoku_solution->show();
    affichage_sudoku->show();

//    qDebug() << "sudoku_fini : " << sudoku_fini;

    return a.exec();
}
