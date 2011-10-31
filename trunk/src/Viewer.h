#include "qglviewer.h"
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
  void printHelperValues();
  
  float ratio, u_max, v_max;
  CourtHelper courtHelper_;
  Court court_;
  Ball ball_;
};
