HOME = ../..
include ($$HOME/common.pri)
TEMPLATE = lib
TARGET = radio
DEPENDPATH += .
INCLUDEPATH += . $$HOME/../command/src
unix:DESTDIR = $$HOME/lib
win32:DESTDIR = $$HOME/bin

# Input
HEADERS += radio_model.h \
    fake_radio_model.h

SOURCES += radio_model.cpp \
    fake_radio_model.cpp

unix:LIBS += -lpthread
win32:LIBS +=