#include "Viewer.h"

#include <QKeyEvent>

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

  court.init();
  ball.init();
}

void Viewer::draw()
{
  glColor3f(1.0, 1.0, 1.0);
  court.draw();
  courtHelper.draw();
  ball.draw();

  float t = ball.getT();
  QString text("t: ");
  text += QString::number(t);
  drawText(10, 20, text);

  float xpos = ball.getXpos();
  text = ("xpos: ");
  text += QString::number(xpos);
  drawText(10, 40, text);

  float ypos = ball.getYpos();
  text = ("ypos: ");
  text += QString::number(ypos);
  drawText(10, 60, text);

  float zpos = ball.getZpos();
  text = ("zpos: ");
  text += QString::number(zpos);
  drawText(10, 80, text);

  float zplus = ball.getZplus();
  text = ("z+: ");
  text += QString::number(zplus);
  drawText(10, 100, text);

  float zminus = ball.getZminus();
  text = ("z-: ");
  text += QString::number(zminus);
  drawText(10, 120, text);
}

void Viewer::animate()
{
  ball.animate();
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
