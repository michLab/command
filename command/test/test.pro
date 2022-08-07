HOME = ..
include ($$HOME/common.pri)
QMAKE_CXXFLAGS += -Wno-deprecated-declarations -DGTEST_HAS_PTHREAD=1
TEMPLATE = app
TARGET = test_command
INCLUDEPATH += $$HOME $$HOME/src $$HOME/submodules/googletest/googletest/include
DESTDIR = $$HOME/bin

# Input
SOURCES += main.cpp \
    radio_test/test_fake_radio_model.cpp

unix:LIBS += -lgtest -lgtest_main -lpthread -L$$HOME/submodules/googletest/build/lib

QT -= gui core
