HOME = ../../
include ($$HOME/common.pri)
TEMPLATE = lib
TARGET = radio_test
DEPENDPATH += $$HOME/src/shared
INCLUDEPATH += . $$HOME $$HOME/src
unix:DESTDIR = $$HOME/lib
win32:DESTDIR = $$HOME/bin
DEFINES += BACKEND_TEST_DIR=\\\"$PWD\\\"

# Input
HEADERS += 

SOURCES +=

unix:LIBS += -L$$HOME/lib
win32:LIBS += -L$$HOME/bin

QT -= gui core
