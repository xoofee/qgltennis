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
  V=60.0;
  x_init = 60.0;
  y_init = 130.0;
  z_init = 10.0;

  x_pos=x_init;
  y_pos=y_init;
  z_pos=z_init;

  Vx=V*sin(rho)*sin(theta);
  Vy=V*sin(rho)*cos(theta);
  Vz=V*cos(rho);

  t=0.0;
  dt=0.2;

  bounce = 0;
}

void Ball::draw()
{
  //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  glColor3f(1.0, 1.0, 0.0);
  // Draw sphere
  glPushMatrix();
  //glTranslatef(158.0, 384.0, 80.0);
  glTranslatef(x_pos, y_pos, z_pos);
  gluSphere(qobj, 5.0, 10, 10);
  glPopMatrix();
  //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void Ball::animate()
{
  x_pos = Vx*t + x_init;
  y_pos = Vy*t + y_init;
  z_pos = Vz*t-0.5*g*t*t + z_init;
  t=t+dt;

  if (z_pos<1.0) {
    bounce++;
    z_pos = 1.1;
    if (bounce == 1) {
      LOG_DEBUG() << "1 bounce";
    }
    else {
      LOG_DEBUG() << "other bounce";
      bounce = 0;

      if (theta == PI/8.0) { theta=9.0*PI/8.0; }
      else theta = PI/8.0;
      Vx=V*sin(rho)*sin(theta);
      Vy=V*sin(rho)*cos(theta);
      Vz=V*cos(rho);
    }
    x_init = x_pos;
    y_init = y_pos;
    z_init = z_pos;
    t=0.0;
  }
}
