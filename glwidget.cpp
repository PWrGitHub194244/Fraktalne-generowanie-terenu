#include "glwidget.h"
#include <iostream>
#include "dane.h"

GLWidget::GLWidget(QWidget * parent):QGLWidget(parent)
{

}
void GLWidget::initializeGL(){

glClearColor(0.0,0.0,0.0,0.0);


}
 float * surfFA;
 bool bnarysowny=false;

float GLWidget::randnum (float min, float max){}
#define fractRand(v) randnum (-v, v)

 int GLWidget::powerOf2 (int size){
     int i, bitcount = 0;


        for (i=0; i<sizeof(int)*8; i++)
        if (size & (1<<i))
            bitcount++;
        if (bitcount == 1)

        return (1);
        else

        return (0);

 }

 void GLWidget::draw3DLine (float x1, float y1, float z1,
          float x2, float y2, float z2){
     glBegin (GL_LINES);
         glVertex3f (x1, y1, z1);
         glVertex3f (x2, y2, z2);
         glEnd ();

 }

 float *GLWidget::allocArray (int size){
     size++;

         return ((float *) malloc (sizeof(float) * size * size));
 }

 float GLWidget::DiamondVals (int i, int j, int stride,
                   int size, int subSize, float *fa){
     if (i == 0)
        return ((float) (fa[(i*size) + j-stride] +
                 fa[(i*size) + j+stride] +
                 fa[((subSize-stride)*size) + j] +
                 fa[((i+stride)*size) + j]) * .25f);
        else if (i == size-1)
        return ((float) (fa[(i*size) + j-stride] +
                 fa[(i*size) + j+stride] +
                 fa[((i-stride)*size) + j] +
                 fa[((0+stride)*size) + j]) * .25f);
        else if (j == 0)
        return ((float) (fa[((i-stride)*size) + j] +
                 fa[((i+stride)*size) + j] +
                 fa[(i*size) + j+stride] +
                 fa[(i*size) + subSize-stride]) * .25f);
        else if (j == size-1)
        return ((float) (fa[((i-stride)*size) + j] +
                 fa[((i+stride)*size) + j] +
                 fa[(i*size) + j-stride] +
                 fa[(i*size) + 0+stride]) * .25f);
        else
        return ((float) (fa[((i-stride)*size) + j] +
                 fa[((i+stride)*size) + j] +
                 fa[(i*size) + j-stride] +
                 fa[(i*size) + j+stride]) * .25f);

 }

 float GLWidget::SquareVals (int i, int j, int stride, int size, float *fa){
     return ((float) (fa[((i-stride)*size) + j-stride] +
                  fa[((i-stride)*size) + j+stride] +
                  fa[((i+stride)*size) + j-stride] +
                  fa[((i+stride)*size) + j+stride]) * .25f);
 }

 void GLWidget::fillArray (float *fa, int size,
                int seedValue, float heightScale, float h){
     int	i, j;
         int	stride;
         int	oddline;
         int subSize;
         float ratio, scale;
     //printf("jest");
         if (!powerOf2(size) || (size==1)) {


        // printf ("Error: fill2DFractArray: size %d is not a power of 2.\n");

         return;
         }


         subSize = size;
         size++;





        // printf ("initialized\n");
         //dump2DFractArray (fa, size);



         ratio = (float) pow (2.,-h);
         scale = heightScale * ratio;



         stride = subSize / 2;
         fa[(0*size)+0] =
           fa[(subSize*size)+0] =
             fa[(subSize*size)+subSize] =
               fa[(0*size)+subSize] = -0.3f;



         while (stride) {

             for (i=stride; i<subSize; i+=stride) {
                 for (j=stride; j<subSize; j+=stride) {
                     fa[(i * size) + j] =
                         scale * fractRand (.5f) +
                         SquareVals (i, j, stride, size, fa);
                     j += stride;
                 }
                 i += stride;
             }

             oddline = 0;
             for (i=0; i<subSize; i+=stride) {
                 oddline = (oddline == 0);
                 for (j=0; j<subSize; j+=stride) {
                     if ((oddline) && !j) j+=stride;


                     fa[(i * size) + j] =
                         scale * fractRand (.5f) +
                        DiamondVals (i, j, stride, size, subSize, fa);


                     if (i==0)
                         fa[(subSize*size) + j] =
                             fa[(i * size) + j];
                     if (j==0)
                         fa[(i*size) + subSize] =
                             fa[(i * size) + j];

                     j+=stride;
                 }
             }

             //printf ("Squares:\n");
             //dump2DFractArray (fa, size);


             /* reduce random number range. */
             scale *= ratio;
             stride >>= 1;
         }


         //printf ("complete\n");
         //dump2DFractArray (fa, size);


 }

 void genNormal (float x1, float y1, float z1,
               float x2, float y2, float z2,
               float x3, float y3, float z3){

 }

 void getNormal (float x1, float y1, float z1,
               float x2, float y2, float z2,
               float x3, float y3, float z3,
               float *normal){

 }
  void GLWidget::paintGL(){
      int randomSeed=90;
            int size=16;
      if(!bnarysowny)
{
      std::cout<<"sax";
surfFA = GLWidget::allocArray (size);
      float surfaceH =  0.9f;

     GLWidget::fillArray (surfFA, size, randomSeed,
                      DEF_HEIGHT_SCALE, surfaceH);

float a=surfFA[1];
bnarysowny=true;
      }
glViewport(200, 400, 300, 30);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

int i,j;
float	x, z, inc;
const int	subSize = size;
size++;
glColor3f(0.0, 0.0, 0.0);

glBegin(GL_LINES);







inc = 2.f / subSize;
z = -1.f;
for (i=0; i<size; i++) {
  x = -1.f;
  for (j=0; j<subSize; j++) {



      glVertex3f (x, surfFA[(i*size)+j], z);
      glVertex3f (x, surfFA[(i*size+j+1)], z);
      if (i<subSize){

              glVertex3f (x, surfFA[(i*size)+j], z);
              glVertex3f (x, surfFA[(i*size+j+1)], z+inc);
      }
      x += inc;
  }
  if (i<subSize)
  {

              glVertex3f (x, surfFA[(i*size)+j], z);
              glVertex3f (x, surfFA[(i*size+j+1)], z+inc);
  }
  z += inc;
  }

         glEnd();




  }

void GLWidget::resizeGL(int w, int h){
glViewport(200, 400, 300, 30);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}
