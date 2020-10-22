#include "main_window_sudoku.h"
#include "ui_main_window_sudoku.h"

main_window_sudoku::main_window_sudoku(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::main_window_sudoku)
{
    ui->setupUi(this);
}

main_window_sudoku::~main_window_sudoku()
{
    delete ui;
}

