#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "warning.h"
#include "opengl.h"
#include "warning2.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

 int MainWindow::powerOf2 (int size){
     int i, bitcount = 0;


        for (i=0; i<sizeof(int)*8; i++)
        if (size & (1<<i))
            bitcount++;
        if (bitcount == 1)

        return (1);
        else

        return (0);

 }

void MainWindow::on_ButtonOK1_clicked()
{
    if(ui->lineEditSzczeg->text().isEmpty()|| ui->lineEditSzorstkosc->text().isEmpty()){
    Warning warningwinow;
    warningwinow.setModal(true);
    warningwinow.exec();
    }
    else if(!MainWindow::powerOf2(ui->lineEditSzczeg->text().toInt())){
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
