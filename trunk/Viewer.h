#include <QGLViewer/qglviewer.h>
#include "CourtHelper.h"
#include "Court.h"
#include "Ball.h"

class Viewer : public QGLViewer
{
protected :
  virtual void init();
  virtual void draw();
  virtual void animate();
  virtual void keyPressEvent(QKeyEvent *e);

private :
  float ratio, u_max, v_max;
  CourtHelper courtHelper;
  Court court;
  Ball ball;
};
