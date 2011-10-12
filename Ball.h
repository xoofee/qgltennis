#ifndef BALL_H
#define BALL_H

#include <GL/glu.h>
#include "vmath.h"

class Ball
{
public:
  Ball() { }
  
  void setInitialPosition(Vector3f initialPosition) {
    initialPosition_ = initialPosition;
  }
  
  Vector3f getCurrentPosition() {
    return position_;
  }

  void init();
  void draw();
  void animate();
  float getTime() { return t; }
  float getZplus() { return zPlusTerm; }
  float getZminus() { return zMinusTerm; }

private:
  GLUquadricObj* qobj;

  static const float PI = 3.141592654;
  static const float GRAVITY = 9.8;

  Vector3f initialPosition_;
  
  // Initial speed in polar coordinates
  float speedModule_;
  float rho, theta;
  
  // Initial speep in cartesian coordinates
  Vector3f speed_;
  
  
  Vector3f position_;

  float t, dt;

  // Helpers for bounce
  int bounce;
  float zPlusTerm;
  float zMinusTerm;
};

#endif // BALL_H
