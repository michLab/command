HOME = ..
message(Home in test_pro = ($$OUT_PWD))
include ($$HOME/common.pri)
QMAKE_CXXFLAGS += -Wno-deprecated-declarations -DGTEST_HAS_PTHREAD=1
TEMPLATE = app
TARGET = test_command
INCLUDEPATH += $$HOME/../command $$HOME/../command/src $$HOME/../command/submodules/googletest/googletest/include
DESTDIR = $$HOME/bin


# Input
SOURCES += main.cpp \
    radio_test/test_fake_radio_model.cpp

unix:LIBS += -lgtest -lgtest_main -lpthread -L$$HOME/../command/submodules/googletest/build/lib

QT -= gui core
