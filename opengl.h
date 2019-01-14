#ifndef OPENGL_H
#define OPENGL_H

#include <QDialog>

namespace Ui {
class OpenGL;
}

class OpenGL : public QDialog
{
    Q_OBJECT

public:


    explicit OpenGL(QWidget *parent = 0);
    ~OpenGL();


private slots:
    void on_ButtonOpenGLGeneruj_clicked();

private:
    Ui::OpenGL *ui;


};

#endif // OPENGL_H
