TEMPLATE = lib
CONFIG = staticlib
SOURCES =  Logger.cpp FileAppender.cpp ConsoleAppender.cpp AbstractStringAppender.cpp AbstractAppender.cpp
HEADERS = Logger.h FileAppender.h ConsoleAppender.h AbstractStringAppender.h AbstractAppender.h

CONFIG += qt

  message (cutelogger)
  message ( DEFINES = $$DEFINES )
  message ( CONFIG = $$CONFIG )
