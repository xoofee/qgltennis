#include "Ball.h"
#include <GL/gl.h>
#include <math.h>

#include "Logger.h"
#include <QDebug>

void Ball::init()
{
  qobj = gluNewQuadric();

  glPointSize(3.0);
  
  // Initial speed Polar
  theta=PI/4.0;
  phi=PI/8.0;
  initialSpeedPolar_ = 60.0;

  // Initial speed Cartesian
  initialSpeed_.x = initialSpeedPolar_*sin(theta)*sin(phi);
  initialSpeed_.y = initialSpeedPolar_*sin(theta)*cos(phi);
  initialSpeed_.z = initialSpeedPolar_*cos(theta);

  speed_ = initialSpeed_;
  position_ = initialPosition_;
      
  t=0.0;
  dt=0.2;

  bounce = 0;
}

void Ball::draw()
{
  //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  glColor3f(1.0, 1.0, 0.0);
  glPushMatrix();
  
  // Draw speed vector
  glBegin(GL_LINES);
    glVertex3fv(position_); glVertex3fv(position_+speed_);
  glEnd();
  
  // Draw sphere
  glTranslatef(position_.x, position_.y, position_.z);
  gluSphere(qobj, 5.0, 10, 10);

  glPopMatrix();
  
  //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void Ball::animate()
{
  position_.x = initialPosition_.x + initialSpeed_.x*t;
  position_.y = initialPosition_.y + initialSpeed_.y*t;
  
  zPlusTerm = initialPosition_.z + initialSpeed_.z*t;
  zMinusTerm = 0.5*GRAVITY*t*t;
  position_.z = zPlusTerm - zMinusTerm;
  
  speed_.z = initialSpeed_.z - GRAVITY*t;
  
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

      if (phi == PI/8.0) { phi=9.0*PI/8.0; }
      else phi = PI/8.0;
      initialSpeed_.x = initialSpeedPolar_*sin(theta)*sin(phi);
      initialSpeed_.y = initialSpeedPolar_*sin(theta)*cos(phi);
      initialSpeed_.z = initialSpeedPolar_*cos(theta);
      speed_ = initialSpeed_;
    }
    
    initialPosition_.x = position_.x;
    initialPosition_.y = position_.y;
    initialPosition_.z = position_.z;
    t=0.0;
  }
}
