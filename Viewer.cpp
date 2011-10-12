#include "Viewer.h"
#include <QKeyEvent>

#include "vmath.h"

using namespace qglviewer;
using namespace std;

bool antiAlias(false);

void Viewer::init()
{
  setSceneCenter( Vec(158,384,0) );
  setSceneRadius(500.0);          // scene has a 100 OpenGL units radius
  camera()->showEntireScene();
  //restoreStateFromFile();

  //glLineWidth(2.0);

  ball_.setInitialPosition(Vector3f(60.0, 130.0, 10.0));
  court_.init();
  ball_.init();
}

void Viewer::draw()
{
  glColor3f(1.0, 1.0, 1.0);
  court_.draw();
  courtHelper_.draw();
  ball_.draw();

  printHelperValues();
}

void Viewer::printHelperValues()
{
  float t = ball_.getTime();
  QString text("time: ");
  text += QString::number(t);
  drawText(10, 40, text);

  text = "ballPos: ";
  Vector3f ballPosition = ball_.getCurrentPosition();
  text += ballPosition.toString().data();
  drawText(10, 60, text);
  
  float zplus = ball_.getZplus();
  float zminus = ball_.getZminus();  
  text = ("ball Z terms: ");
  text += QString::number(zplus);
  text += " - ";
  text += QString::number(zminus);
  drawText(10, 80, text);
  
  text = "Press ENTER to bounce ball";
  drawText(200, 20, text);
}

void Viewer::animate()
{
  ball_.animate();
}

void Viewer::keyPressEvent(QKeyEvent *e)
{
  switch (e->key())
  {
  case Qt::Key_T : {
    // 'T' changes the projection type : perspective or orthogonal
    //printf("Camera changed to ");
    if (camera()->type() == Camera::ORTHOGRAPHIC) {
      camera()->setType(Camera::PERSPECTIVE);
      //printf("Perspective\n");
    }
    else {
      camera()->setType(Camera::ORTHOGRAPHIC);
      //printf("Ortho\n");
    }
    updateGL();
  }
  case Qt::Key_K : {
    antiAlias = !antiAlias;
    if (antiAlias) {
      glEnable(GL_LINE_SMOOTH);
      glEnable(GL_POLYGON_SMOOTH);
      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
    else {
      glDisable(GL_LINE_SMOOTH);
      glDisable(GL_POLYGON_SMOOTH);
      glDisable(GL_BLEND);
    }
    updateGL();
  }
  default:
    QGLViewer::keyPressEvent(e);
  }
}
