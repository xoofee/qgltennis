#include "Court.h"
#include <GL/gl.h>

#include <qimage.h>
#include <QGLWidget>

#include <math.h>

#include "Logger.h"
#include <QDebug>

void Court::init()
{
  // Enable GL textures
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

  // Nice texture coordinate interpolation
  glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );

  loadImage();
}

void Court::draw()
{
  // Display the quad
  glEnable(GL_TEXTURE_2D);
  glNormal3f(0.0, 0.0, 1.0);
  glBegin(GL_QUADS);

  // Textura solo Pista
//  glTexCoord2f(474.0/2048.0, 418.0/2048.0); glVertex2f(50.0,150.0);
//  glTexCoord2f(474.0/2048.0, 1630.0/2048.0); glVertex2f(50.0, 618.0);
//  glTexCoord2f(1577.0/2048.0, 1630.0/2048.0); glVertex2f(266.0, 618.0);
//  glTexCoord2f(1577.0/2048.0, 418.0/2048.0); glVertex2f(266.0, 150.0);

    glTexCoord2f(0.0, 0.0); glVertex2f(-42.53, -11.405);
    glTexCoord2f(0.0, 1.0); glVertex2f(-42.53, 779.405);
    glTexCoord2f(1.0, 1.0); glVertex2f( 358.53, 779.405);
    glTexCoord2f(1.0, 0.0); glVertex2f( 358.53, -11.405);

  glEnd();
  glDisable(GL_TEXTURE_2D);
}

void Court::loadImage()
{
  QString name("./textures/s02_court.jpg");
  LOG_DEBUG() << "Loading " << name;

  QImage img(name);

  if (img.isNull()) {
    LOG_DEBUG() << name << "Not found";
    
    name = "./debug/textures/s02_court.jpg";
    img.load(name);
    
    if (img.isNull()) {
      LOG_DEBUG() << "Unable to load file " << name << "unsupported file format";
      return;
    }
  }
  
  LOG_WARNING() << "Loading " << name.toLatin1().constData() << ", " << img.width() << "x" << img.height() << " pixels";

  // 1E-3 needed. Just try with width=128 and see !
  int newWidth  = 1<<(int)(1+log(img.width() -1+1E-3) / log(2.0));
  int newHeight = 1<<(int)(1+log(img.height()-1+1E-3) / log(2.0));

  if ((img.width()!=newWidth) || (img.height()!=newHeight)) {
    qWarning("Image size set to %dx%d pixels", newWidth, newHeight);
    img = img.copy(0, 0, newWidth, newHeight);
  }

  QImage glImg = QGLWidget::convertToGLFormat(img);  // flipped 32bit RGBA

  // Bind the img texture...
  glTexImage2D(GL_TEXTURE_2D, 0, 4, glImg.width(), glImg.height(), 0,
               GL_RGBA, GL_UNSIGNED_BYTE, glImg.bits());
}
