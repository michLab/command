HOME = ../..
include ($$HOME/common.pri)
TEMPLATE = lib
TARGET = command_ui
DEPENDPATH += .
INCLUDEPATH += . $$HOME/src
unix:DESTDIR = $$HOME/lib
win32:DESTDIR = $$HOME/bin

# Input
HEADERS += 

SOURCES +=

unix:LIBS +=
win32:LIBS +=