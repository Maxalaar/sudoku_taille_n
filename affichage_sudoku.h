#ifndef AFFICHAGE_SUDOKU_H
#define AFFICHAGE_SUDOKU_H

#include <QMainWindow>
#include <QOpenGLWindow>
#include <QSurfaceFormat>
#include <QOpenGLFunctions>
#include <QtOpenGL>
#include <GL/glu.h>

#include "sudoku.h"

class Affichage_sudoku : public QOpenGLWindow
{
public:
    Affichage_sudoku(Sudoku* sudoku_cible, QWidget *parent = nullptr);

protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();

private:
    Sudoku* sudoku_cible;
};

#endif // AFFICHAGE_SUDOKU_H
