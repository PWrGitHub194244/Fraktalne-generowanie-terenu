#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QGLWidget>
#include <math.h>
class GLWidget : public QGLWidget
{
    Q_OBJECT
public:

    explicit GLWidget(QWidget *parent =0);
    void initializeGL();
    #define DEF_HEIGHT_SCALE 1.f
    void resizeGL(int w, int h);
    float randnum (float min, float max);

     int powerOf2 (int size);
     void draw3DLine (float x1, float y1, float z1,
              float x2, float y2, float z2);
     float *allocArray (int size);

     float DiamondVals (int i, int j, int stride,
                       int size, int subSize, float *fa);
     float SquareVals (int i, int j, int stride, int size, float *fa);
     void fillArray (float *fa, int size,
                    int seedValue, float heightScale, float h);
     void genNormal (float x1, float y1, float z1,
                   float x2, float y2, float z2,
                   float x3, float y3, float z3);
     void getNormal (float x1, float y1, float z1,
                   float x2, float y2, float z2,
                   float x3, float y3, float z3,
                   float *normal);
     void paintGL();


};

#endif // GLWIDGET_H
