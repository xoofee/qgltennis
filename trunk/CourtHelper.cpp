#include "CourtHelper.h"

#include "vmath.h"
#include <GL/gl.h>

Vector3f cornerPoint1(50.0, 150.0, 50.0), cornerPoint2(50.0, 618.0, 50.0), cornerPoint3(266.0, 618.0, 50.0), cornerPoint4(266.0,150.0, 50.0);
Vector3f leftSingleLineEndPoint1(77.0, 150.0, 50.0), leftSingleLineEndPoint2(77.0, 618.0, 50.0);
Vector3f rightSingleLineEndPoint1(239.0, 150.0, 50.0), rightSingleLineEndPoint2(239.0, 618.0, 50.0);
Vector3f middleLineEndPoint1(50.0, 384.0, 50.0), middleLineEndPoint2(266.0, 384.0, 50.0);
Vector3f upperServiceLineEndPoint1(77.0, 258.0, 50.0), upperServiceLineEndPoint2(239.0, 258.0, 50.0);
Vector3f lowerServiceLineEndPoint1(77.0, 510, 50.0), lowerServiceLineEndPoint2(239.0, 510, 50.0);
Vector3f serviceLineTPoint1(158.0, 258.0, 50.0), serviceLineTPoint2(158.0, 510, 50.0);

CourtHelper::CourtHelper()
{
}

void CourtHelper::draw()
{
  glColor3f(1.0, 0.0, 0.0);

  glBegin(GL_LINE_LOOP);
    glNormal3f(0.0, 0.0, 1.0);
    glVertex3fv(cornerPoint1); glVertex3fv(cornerPoint2); glVertex3fv(cornerPoint3);
    glVertex3fv(cornerPoint4); glVertex3fv(cornerPoint1);
  glEnd();
  glBegin(GL_LINES);
    glNormal3f(0.0, 0.0, 1.0);
    glVertex3fv(leftSingleLineEndPoint1); glVertex3fv(leftSingleLineEndPoint2);
    glVertex3fv(rightSingleLineEndPoint1); glVertex3fv(rightSingleLineEndPoint2);
    glVertex3fv(middleLineEndPoint1); glVertex3fv(middleLineEndPoint2);
    glVertex3fv(upperServiceLineEndPoint1); glVertex3fv(upperServiceLineEndPoint2);
    glVertex3fv(lowerServiceLineEndPoint1); glVertex3fv(lowerServiceLineEndPoint2);
    glVertex3fv(serviceLineTPoint1); glVertex3fv(serviceLineTPoint2);
  glEnd();
}
