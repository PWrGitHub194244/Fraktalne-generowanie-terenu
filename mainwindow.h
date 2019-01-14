#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "warning.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
   int powerOf2 (int size);


private slots:
    void on_ButtonOK1_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
