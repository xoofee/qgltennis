# Loads an image file and texture maps a polygon with it.

# Pedagogical example that shows how to apply a texture on a 3D object.
# Inspired from the Qt texture example.

# The Qt <code>QImage</code> class and its <code>convertToGLFormat()</code> function are used to
# load any image format. The image is included in a larger image whose dimensions are powers of two.
# This is not required if your hardware supports the GL_TEXTURE_RECTANGLE extension. Feel free to
# cut and paste.

TEMPLATE = app
TARGET   = ../../qgltennis 

HEADERS  = Viewer.h \
    CourtHelper.h \
    Court.h \
    Ball.h
SOURCES  = main.cpp  \
    Viewer.cpp \
    CourtHelper.cpp \
    Court.cpp \
    Ball.cpp

DISTFILES += *.png

QT *= xml opengl

CONFIG += qt opengl warn_on thread rtti
#CONFIG -= release debug_and_release debug_and_release_target shared
# --------------------------------------------------------------------------------------

# The remaining of this configuration tries to automatically detect the library paths.
# In your applications, you can probably simply use (see doc/compilation.html for details) :
unix {
  INCLUDEPATH *= /home/tomas/qgltennis/ /home/tomas/qgltennis/vmath-0.9/src /home/tomas/qgltennis/cutelogger/src
  LIBS *= -L/home/tomas/qgltennis/QGLViewer -lQGLViewer

  MOC_DIR = .moc
  OBJECTS_DIR = .obj
}

win32 {
  INCLUDEPATH *= ../QGLViewer ../vmath ../cutelogger
  LIBS *= -L.. -lQGLViewerd2 -L../cutelogger -lcutelogger -L../vmath -lvmath 
}

message ( src )
message ( DEFINES = $$DEFINES )
message ( CONFIG = $$CONFIG )
