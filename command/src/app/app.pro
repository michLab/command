HOME = ../..
include ($$HOME/common.pri)
TEMPLATE = app
TARGET = command
DEPENDPATH += .
INCLUDEPATH += $$HOME/../command/src
DESTDIR = $$HOME/bin


win32:CONFIG += console

SOURCES += main.cpp

unix:LIBS += -L$$HOME/lib
win32:LIBS += -L$$HOME/bin