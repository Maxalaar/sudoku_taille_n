#include "sudoku.h"

Sudoku::Sudoku(int taille_grille)
{
    this->dimension = taille_grille;
    this->caractere_max = dimension * dimension;

    //On crée la liste des valeur possible
    for(int i = 1; i < caractere_max+1; i++)
    {
        liste_caracter_possible.push_back(i);
    }

    //On crée la grille du sudoku
    for(int i = 0; i < caractere_max; i++)
    {
        QVector<Cellule> ligne_grille_prov;

        for(int j = 0; j < caractere_max; j++)
        {
            ligne_grille_prov.push_back(Cellule());
        }

        this->grille.push_back(ligne_grille_prov);
    }

    //On initialise les grille du tableau
    for(int i = 0; i < caractere_max; i++)
    {
        for(int j = 0; j < caractere_max; j++)
        {
            grille[i][j].init(i, j, liste_caracter_possible, liste_pointeur_cellule_contrainte(i, j));
        }
    }
}

QVector<Cellule*> Sudoku::liste_pointeur_cellule_contrainte(int x, int y)
{
    QVector<Cellule*> pointeur_cellule_contrainte;

    //Liste des pointeurs ligne
    for(int i = 0; i < caractere_max; i++)
    {
        if(i != x)
        {
            pointeur_cellule_contrainte.push_back(&(grille[i][y]));
        }
    }

    //Liste des pointeurs colonne
    for(int i = 0; i < caractere_max; i++)
    {
        if(i != y)
        {
            pointeur_cellule_contrainte.push_back(&(grille[x][i]));
        }
    }

    //Liste des pointeurs carré
    //Petite optimisation ! verification de la non redondance des pointeurs
    int position_initiale_carre_x;
    int position_initiale_carre_y;

    int i;
    int j;

    for(i = 0; i * dimension <= x ; i++)
    {

    }
    position_initiale_carre_x = (i-1) * dimension;

    for(j = 0; j * dimension <= y ; j++)
    {

    }
    position_initiale_carre_y = (j-1) * dimension;

    for(int k = position_initiale_carre_x; k < position_initiale_carre_x + dimension; k++)
    {
        for(int l = position_initiale_carre_y; l < position_initiale_carre_y + dimension; l++)
        {
            if(k != x || l != y)
            {
                pointeur_cellule_contrainte.push_back(&(grille[k][l]));
            }
        }
    }

    return pointeur_cellule_contrainte;
}

Sudoku sudoku_remplissage_fichier(QString nom_fichier)
{
    QFile fichier(nom_fichier);
    qDebug() << fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&fichier);

    int iterateur = 0;
    QVector<int> liste_valeur;

    while(! flux.atEnd())
    {
        QString valeur;
        flux >> valeur;
        liste_valeur.push_back(valeur.toInt());
    };

    qDebug() <<"taille liste_valeur : " << liste_valeur.size();

    Sudoku sudoku(liste_valeur[iterateur]);
    iterateur = iterateur + 1;

    for(int i = 0; i < sudoku.caractere_max; i++)
    {
        for(int j = 0; j < sudoku.caractere_max; j++)
        {
            if(liste_valeur[iterateur] != 0)
            {
                sudoku.grille[j][i].placer_valeur(liste_valeur[iterateur]);
            }
            iterateur = iterateur + 1;
        }
    }

    return sudoku;
}

//QVector<int> Sudoku::liste_valeur_impossible_ligne(int x, int y)
//{
//    QVector<int> liste_valeur_impossible;

//    for(int i = 0; i < caractere_max; i++)
//    {
//        if(grille[x][i].size() == 1 && i != y)
//        {
//            liste_valeur_impossible.push_back(grille[x][i][0]);
//        }
//    }

//    return liste_valeur_impossible;
//}

//QVector<int> Sudoku::liste_valeur_impossible_colonne(int x, int y)
//{
//    QVector<int> liste_valeur_impossible;

//    for(int i = 0; i < caractere_max; i++)
//    {
//        if(grille[i][y].size() == 1 && i != x)
//        {
//            liste_valeur_impossible.push_back(grille[i][y][0]);
//        }
//    }

//    return liste_valeur_impossible;
//}

//QVector<int> Sudoku::liste_valeur_impossible_carre(int x, int y)
//{
//    QVector<int> liste_valeur_impossible;

//    int position_initiale_carre_x;
//    int position_initiale_carre_y;

//    int i;
//    int j;

//    for(i = 0; i * dimension <= x ; i++)
//    {

//    }
//    position_initiale_carre_x = (i-1) * dimension;

//    for(j = 0; j * dimension <= y ; j++)
//    {

//    }
//    position_initiale_carre_y = (j-1) * dimension;

//    for(int k = position_initiale_carre_x; k < position_initiale_carre_x + dimension; k++)
//    {
//        for(int l = position_initiale_carre_y; l < position_initiale_carre_y + dimension; l++)
//        {
//            if(grille[k][l].size() == 1 && k != x && l != y)
//            {
//                liste_valeur_impossible.push_back(grille[k][l][0]);
//            }
//        }
//    }

//    return liste_valeur_impossible;
//}

//QVector<int> Sudoku::liste_valeur_possible_cellule(int x, int y)
//{
//    QVector<int> liste_valeur_possible = this->liste_caracter_possible;
//    QVector<int> liste_valeur_impossible;

//    liste_valeur_impossible.append(liste_valeur_impossible_ligne(x, y));
//    liste_valeur_impossible.append(liste_valeur_impossible_colonne(x, y));
//    liste_valeur_impossible.append(liste_valeur_impossible_carre(x, y));

//    for(int i = 0; i < liste_valeur_impossible.size(); i++)
//    {
//        for(int j = 0; j < liste_valeur_possible.size(); j++)
//        {
//            if(liste_valeur_impossible[i] == liste_valeur_possible[j])
//            {
//                liste_valeur_possible.remove(j);
//            }
//        }
//    }

//    return liste_valeur_possible;
//}

//void Sudoku::placer_valeur(int x, int y)
//{
//    grille[x][y].placer_valeur(grille[x][y].liste_valeur_possible[QRandomGenerator::global()->bounded(0, liste_valeur_possible.size())]
//}

void Sudoku::copie_sudoku(Sudoku* sudoku)
{
    //On crée la grille du sudoku
    for(int i = 0; i < caractere_max; i++)
    {
        for(int j = 0; j < caractere_max; j++)
        {
            this->grille[i][j].valeur_fix = sudoku->grille[i][j].valeur_fix;
            this->grille[i][j].liste_valeur_possible = sudoku->grille[i][j].liste_valeur_possible;
        }
    }
}

bool initialisation_aleatoire(Sudoku* sudoku_cible, double pourcentage_remplissage)
{
    bool remplissage_possible;
    int nombre_cellule = sudoku_cible->caractere_max * sudoku_cible->caractere_max;
    int nombre_cellule_affecter = (int)((double)pourcentage_remplissage * (double)nombre_cellule);

    //On liste toutes les cellules du tableau pour les tirée aléatoirmeent
    QVector<Cellule*> liste_cellule_visiter_pointeur;

    for(int i = 0; i < sudoku_cible->caractere_max; i++)
    {
        for(int j = 0; j < sudoku_cible->caractere_max; j++)
        {
            liste_cellule_visiter_pointeur.push_back(&(sudoku_cible->grille[i][j]));
        }
    }

    //Pour chaque cellule a affecter
    for(int i = 0; i < nombre_cellule_affecter; i++)
    {
        int valeur_aleatoir = QRandomGenerator::global()->bounded(0, liste_cellule_visiter_pointeur.size());
        Cellule* cellule_choisie_pointeur = liste_cellule_visiter_pointeur[valeur_aleatoir];

        liste_cellule_visiter_pointeur.remove(valeur_aleatoir);

        QVector<int> liste_valeur_possible = cellule_choisie_pointeur->liste_valeur_possible;
        if(liste_valeur_possible.size() > 0)
        {
            cellule_choisie_pointeur->placer_valeur(liste_valeur_possible[QRandomGenerator::global()->bounded(0, liste_valeur_possible.size())]);
        }
        else
        {
            qDebug() << "Attention le sudoku ne peut pas étre resolue, cellule :" << cellule_choisie_pointeur->position_x << "," << cellule_choisie_pointeur->position_y;
            remplissage_possible = false;
        }
    }

    return remplissage_possible;
}

//void creation_sudoku_possibilités(Sudoku* sudoku)
//{
//    for(int i = 0; i < sudoku->caractere_max; i++)
//    {
//        for(int j = 0; j < sudoku->caractere_max; j++)
//        {
//            if(sudoku->grille[i][j].size() == 0)
//            {
//                QVector<int> liste_valeur_possible = sudoku->liste_valeur_possible_cellule(i, j);
//                sudoku->grille[i][j].append(liste_valeur_possible);
//            }
//        }
//    }
//}

bool resolution_sudoku_csp_init(Sudoku* sudoku, Sudoku* sudoku_solution)
{
    bool solution_trouve = true;

    //On répète cette boucle a chaque fois que on change une valeur
    bool changement = false;

    do
    {
        changement = false;
        for(int i = 0; i < sudoku->caractere_max; i++)
        {
            for(int j = 0; j < sudoku->caractere_max; j++)
            {
                //Si il y a plus de choix alors que une valeur n'est pas fixer il faut remonter au neud précédent
                if (sudoku->grille[i][j].valeur_fix == -1 && sudoku->grille[i][j].liste_valeur_possible.size() <= 0) {
                    return false;
                }

                //Si il y a qu'un seule choix possible on le place
                else if(sudoku->grille[i][j].valeur_fix == -1 && sudoku->grille[i][j].liste_valeur_possible.size() == 1)
                {
                    sudoku->grille[i][j].placer_valeur(sudoku->grille[i][j].liste_valeur_possible[0]);
                    changement = true;
                }
            }
        }

    }
    while(changement == true);

    //On cherche les cellule qui on le moins de choix
    QVector<Cellule*> liste_taille_cellule_possibilite;

    //Pour chaque cellule
    for(int i = 0; i < sudoku->caractere_max; i++)
    {
        for(int j = 0; j < sudoku->caractere_max; j++)
        {
            //Si la cellule n'est pas fixer
            if(sudoku->grille[i][j].valeur_fix == -1)
            {
                //Si la liste "liste_taille_cellule_possibilite" est vide
                if(liste_taille_cellule_possibilite.size() == 0)
                {
                    liste_taille_cellule_possibilite.push_back(&(sudoku->grille[i][j]));
                }
                //Si la liste "liste_taille_cellule_possibilite" est pas vide
                else
                {
                    bool valeur_placer = false;
                    for(int k = 0; k < liste_taille_cellule_possibilite.size(); k++)
                    {
                        if(sudoku->grille[i][j].liste_valeur_possible.size() <= liste_taille_cellule_possibilite[k]->liste_valeur_possible.size()/*|| k == liste_taille_cellule_possibilite.size()*/)
                        {
                            liste_taille_cellule_possibilite.insert(k, &(sudoku->grille[i][j]));
                            k = liste_taille_cellule_possibilite.size() + 1;
                            valeur_placer = true;
                        }
                    }

                    if(valeur_placer == false)
                    {
                        liste_taille_cellule_possibilite.push_back(&(sudoku->grille[i][j]));
                    }
                }
            }
        }
    }

//    qDebug() << "Liste taille possibiliter :";
//    qDebug() << "taille liste :" << liste_taille_cellule_possibilite.size();

//    for(int k = 0; k < liste_taille_cellule_possibilite.size(); k++)
//    {
//        qDebug() << liste_taille_cellule_possibilite[k]->liste_valeur_possible.size();
//    }

//    //Pour toutes les cellules du sudoku
//    for(int i = 0; i < sudoku->caractere_max; i++)
//    {
//        for(int j = 0; j < sudoku->caractere_max; j++)
//        {
//            //Si il y a une valeur non placer c'est pas finit
//            if(solution_trouve == true && sudoku->grille[i][j].valeur_fix == -1)
//            {
//                solution_trouve = false;
//            }

//            //Si il y a plusieur choix et la cellule n'est pas fixer
//            if(sudoku->grille[i][j].valeur_fix == -1 && sudoku->grille[i][j].liste_valeur_possible.size() > 0)
//            {
//                QVector<int> liste_valeur_possible = sudoku->grille[i][j].liste_valeur_possible;

//                for(int k = 0; k < liste_valeur_possible.size(); k++)
//                {
//                    Sudoku* sudoku_prov = new Sudoku(sudoku->dimension);
//                    sudoku_prov->copie_sudoku(sudoku);
//                    qDebug() << "On place une valeur";
//                    sudoku_prov->grille[i][j].placer_valeur(liste_valeur_possible[k]);

//                    bool resultat = false;
//                    resultat = resolution_sudoku_csp_init(sudoku_prov,  sudoku_solution);

//                    sudoku_prov->~Sudoku();

//                    if(resultat == true)
//                    {
//                        return true;
//                    }
//                }
//            }
//        }
//    }

    if(liste_taille_cellule_possibilite.size() == 0)
    {
        solution_trouve = true;
        sudoku_solution->copie_sudoku(sudoku);
    }
    else
    {
        for(int i = 0; i < liste_taille_cellule_possibilite.size(); i++)
        {
            QVector<int> liste_valeur_possible = liste_taille_cellule_possibilite[i]->liste_valeur_possible;

            for(int k = 0; k < liste_valeur_possible.size(); k++)
            {
                Sudoku* sudoku_prov = new Sudoku(sudoku->dimension);
                sudoku_prov->copie_sudoku(sudoku);

                sudoku_prov->grille[liste_taille_cellule_possibilite[i]->position_x][liste_taille_cellule_possibilite[i]->position_y].placer_valeur(liste_valeur_possible[k]);

                bool resultat = false;
                resultat = resolution_sudoku_csp_init(sudoku_prov,  sudoku_solution);

                sudoku_prov->~Sudoku();

                if(resultat == true)
                {
                    return true;
                }
            }
        }

        solution_trouve = false;
        qDebug() << "c'est une impasse";
    }

    return solution_trouve;
}
