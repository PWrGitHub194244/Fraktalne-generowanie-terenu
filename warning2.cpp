#include "warning2.h"
#include "ui_warning2.h"

Warning2::Warning2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Warning2)
{
    ui->setupUi(this);
}

Warning2::~Warning2()
{
    delete ui;
}
