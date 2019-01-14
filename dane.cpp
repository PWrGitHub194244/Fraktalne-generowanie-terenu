#include "dane.h"
#include "ui_dane.h"
#include "warning.h"
#include "opengl.h"
#include "warning2.h"
Dane::Dane(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dane)
{
    ui->setupUi(this);
}

Dane::~Dane()
{
    delete ui;
}
int Dane::powerOf2 (int size){
    int i, bitcount = 0;


       for (i=0; i<sizeof(int)*8; i++)
       if (size & (1<<i))
           bitcount++;
       if (bitcount == 1)

       return (1);
       else

       return (0);

}

void Dane::on_ButtonOK1_clicked()
{
    if(ui->lineEditSzczeg->text().isEmpty()|| ui->lineEditSzorstkosc->text().isEmpty()){
   Warning warningwinow;
    warningwinow.setModal(true);
    warningwinow.exec();
   } else if(!Dane::powerOf2(ui->lineEditSzczeg->text().toInt())){
        Warning2 warningwinow;
        warningwinow.setModal(true);
        warningwinow.exec();
    }
    else

    {
        this->close();
        OpenGL openglowindow;
        openglowindow.setModal(true);
        openglowindow.exec();

    }
}
