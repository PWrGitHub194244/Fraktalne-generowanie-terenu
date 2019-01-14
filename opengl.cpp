#include "opengl.h"
#include "ui_opengl.h"
#include "dane.h"


OpenGL::OpenGL(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenGL)
{
    ui->setupUi(this);
}

OpenGL::~OpenGL()
{
    delete ui;
}



void OpenGL::on_ButtonOpenGLGeneruj_clicked()
{
    this->close();

   Dane danewinow;
    danewinow.setModal(true);
    danewinow.exec();
}
