#ifndef MAIN_WINDOW_SUDOKU_H
#define MAIN_WINDOW_SUDOKU_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class main_window_sudoku; }
QT_END_NAMESPACE

class main_window_sudoku : public QMainWindow
{
    Q_OBJECT

public:
    main_window_sudoku(QWidget *parent = nullptr);
    ~main_window_sudoku();

private:
    Ui::main_window_sudoku *ui;
};
#endif // MAIN_WINDOW_SUDOKU_H
