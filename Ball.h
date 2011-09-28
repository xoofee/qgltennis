#ifndef BALL_H
#define BALL_H

#include <GL/glu.h>

class Ball
{
public:
  Ball() { }
  void init();
  void draw();
  void animate();
  float getT() { return t; }
  float getXpos() { return x_pos; }
  float getYpos() { return y_pos; }
  float getZpos() { return z_pos; }
  float getZplus() { return (Vz*t+z_init); }
  float getZminus() { return (-0.5*g*t*t); }

private:
  GLUquadricObj* qobj;

  static const float PI = 3.141592654;
  static const float g = 9.8;

  float x_init, y_init, z_init;
  float rho, theta;
  float V;

  float x_pos, y_pos, z_pos;
  float Vx, Vy, Vz;
  float t, dt;

  int bounce;
};

#endif // BALL_H
