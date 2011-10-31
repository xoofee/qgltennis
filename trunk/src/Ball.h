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
  
  Vector3f getPosition() {
    return position_;
  }

  Vector3f getSpeed() {
    return speed_;
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
  
  // Initial speed 
  float initialSpeedPolar_; // in polar coordinates
  float theta, phi;
  Vector3f initialSpeed_;   // in cartesian coordinates
  
  Vector3f position_;
  Vector3f speed_;

  float t, dt;

  // Helpers for bounce
  int bounce;
  float zPlusTerm;
  float zMinusTerm;
};

#endif // BALL_H
