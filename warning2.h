#ifndef WARNING2_H
#define WARNING2_H

#include <QDialog>

namespace Ui {
class Warning2;
}

class Warning2 : public QDialog
{
    Q_OBJECT

public:
    explicit Warning2(QWidget *parent = 0);
    ~Warning2();


private:
    Ui::Warning2 *ui;
};

#endif // WARNING2_H
