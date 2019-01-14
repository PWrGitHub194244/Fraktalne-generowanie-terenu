#ifndef DANE_H
#define DANE_H

#include <QDialog>

namespace Ui {
class Dane;
}

class Dane : public QDialog
{
    Q_OBJECT

public:
    explicit Dane(QWidget *parent = 0);
    ~Dane();
    int powerOf2 (int size);

private slots:
    void on_ButtonOK1_clicked();

private:
    Ui::Dane *ui;
};

#endif // DANE_H
