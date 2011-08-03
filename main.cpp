#include "Viewer.h"
#include <qapplication.h>

int main(int argc, char** argv)
{
  QApplication application(argc,argv);

  Viewer viewer;

  viewer.setWindowTitle("qtennis");
  viewer.show();
  
  return application.exec();
}
