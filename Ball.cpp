#include "Ball.h"
#include <GL/gl.h>
#include <math.h>

#include "Logger.h"
#include <QDebug>

void Ball::init()
{
  qobj = gluNewQuadric();

  glPointSize(3.0);
  rho=PI/4.0;
  theta=PI/8.0;
  speedModule_=60.0;

  position_ = initialPosition_;

  speed_.x = speedModule_*sin(rho)*sin(theta);
  speed_.y = speedModule_*sin(rho)*cos(theta);
  speed_.z = speedModule_*cos(rho);

  t=0.0;
  dt=0.2;

  bounce = 0;
}

void Ball::draw()
{
  //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  // Draw sphere
  glColor3f(1.0, 1.0, 0.0);
  glPushMatrix();
  glTranslatef(position_.x, position_.y, position_.z);
  gluSphere(qobj, 5.0, 10, 10);
  
  
  glPopMatrix();
  
  //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void Ball::animate()
{
  position_.x = initialPosition_.x + speed_.x*t;
  position_.y = initialPosition_.y + speed_.y*t;
  
  zPlusTerm = initialPosition_.z + speed_.z*t;
  zMinusTerm = 0.5*GRAVITY*t*t;
  position_.z = zPlusTerm - zMinusTerm;
  
  t=t+dt;

  if (position_.z<1.0) {
    bounce++;
    position_.z = 1.1;
    if (bounce == 1) {
      LOG_DEBUG() << "1 bounce";
    }
    else {
      LOG_DEBUG() << "other bounce";
      bounce = 0;

      if (theta == PI/8.0) { theta=9.0*PI/8.0; }
      else theta = PI/8.0;
      speed_.x = speedModule_*sin(rho)*sin(theta);
      speed_.y = speedModule_*sin(rho)*cos(theta);
      speed_.z = speedModule_*cos(rho);
    }
    
    initialPosition_.x = position_.x;
    initialPosition_.y = position_.y;
    initialPosition_.z = position_.z;
    t=0.0;
  }
}
