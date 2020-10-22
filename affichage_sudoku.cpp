#include "affichage_sudoku.h"

Affichage_sudoku::Affichage_sudoku(Sudoku* sudoku_cible, QWidget *parent)
{
    this->sudoku_cible = sudoku_cible;
    QString titre = "Sudoku d'ordre ";
    titre += QString::number(sudoku_cible->dimension);
    titre += " (" +  QString::number(sudoku_cible->caractere_max) + ", " + QString::number(sudoku_cible->caractere_max) + ")";
    this->setTitle(titre);
    this->resize(800, 800);
}

void Affichage_sudoku::initializeGL()
{

}

void Affichage_sudoku::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void Affichage_sudoku::paintGL()
{
    //On colore le fond en blanc
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    //On definie la taille d'une cellule en relatif
    double taille_cellule_x_re = 2/(double)(this->sudoku_cible->caractere_max);
    double taille_cellule_y_re = 2/(double)(this->sudoku_cible->caractere_max);

    //On definie la taille d'une cellule en relatif
    double taille_cellule_x_ab = (double)((double)height()/(double)(this->sudoku_cible->caractere_max));
    double taille_cellule_y_ab = (double)((double)width()/(double)(this->sudoku_cible->caractere_max));

    //On cherche la taille max d'un caractere
    double taille_max_caractere = -1;
    for(int i = 0; i < sudoku_cible->caractere_max; i++)
    {
        for(int j = 0; j < sudoku_cible->caractere_max; j++)
        {
            if(sudoku_cible->grille[i][j].valeur_fix != -1 && QString::number(sudoku_cible->grille[i][j].valeur_fix).size() > taille_max_caractere)
            {
                taille_max_caractere = QString::number(sudoku_cible->grille[i][j].valeur_fix).size();
            }
        }
    }


    //On calclcule quelle va étre la taille d'un caractere
    int taille_caractere;
    if(taille_cellule_x_ab > (double)((double)taille_cellule_y_ab/(double)taille_max_caractere))
    {
        taille_caractere = (double)((double)taille_cellule_y_ab/(double)taille_max_caractere);
    }
    else
    {
         taille_caractere = taille_cellule_x_ab;
    }


    //On affiche les lignes verticale de la grille
    for(int i = 0; i < sudoku_cible->caractere_max; i++)
    {
        glLineWidth(taille_cellule_x_re/10);
        glBegin(GL_LINES);
        glColor3f(0, 0, 0);
        double position_point_x = taille_cellule_x_re * i - 1;
        glVertex2f(position_point_x, -1);
        glVertex2f(position_point_x, 1);
        glEnd();
    }

    //On affiche les lignes horizontal de la grille
    for(int i = 0; i < sudoku_cible->caractere_max; i++)
    {
        glLineWidth(taille_cellule_x_re/10);
        glBegin(GL_LINES);
        glColor3f(0, 0, 0);
        double position_point_y = taille_cellule_y_re * i - 1;
        glVertex2f(-1, position_point_y);
        glVertex2f(1, position_point_y);
        glEnd();
    }

    //On affiche la valeur de chaque cellules de la grille
    for(int i = 0; i < sudoku_cible->caractere_max; i++)
    {
        for(int j = 0; j < sudoku_cible->caractere_max; j++)
        {
            //Pour afficher la valeur on verifie que le caractere n'est pas le caractere vide (soit ici 0)
            if(sudoku_cible->grille[i][j].valeur_fix != -1)
            {
                int caractere = sudoku_cible->grille[i][j].valeur_fix;
                QPainter painter(this);
                QColor fontColor = QColor(0, 0, 0, 255);
                painter.setPen(fontColor);
                painter.setFont(QFont("Arial", taille_caractere));
                painter.drawText(i * taille_cellule_y_ab, j * taille_cellule_x_ab, taille_cellule_y_ab, taille_cellule_x_ab, Qt::AlignCenter, QString::number(caractere));
                painter.end();
            }
        }
    }
}
