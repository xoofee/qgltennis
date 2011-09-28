#include "Viewer.h"
#include <qapplication.h>

#include "Logger.h"
#include <FileAppender.h>


int main(int argc, char** argv)
{
  QApplication application(argc,argv);

  FileAppender fileAppender("qgltennis.log");
  fileAppender.setFormat("[%t{dd-MM-yyyy HH:mm:ss.zzz}] (%-7l) %f:%i | %C | %m |\n");
  Logger::registerAppender(&fileAppender);

  LOG_INFO("Starting qgltennis");
  
  Viewer viewer;

  viewer.setWindowTitle("qgltennis");
  viewer.show();
  
  return application.exec();
}
