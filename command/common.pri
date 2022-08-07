
CONFIG(debug, debug|release): DEFINES += DEBUG
CONFIG(release, debug|release): DEFINES += RELEASE
VERSION = 1.0.0
VERSION_STR = '\\"$${VERSION}\\"'
DEFINES += COMMAND_VERSION=\"$${VERSION_STR}\"
CONFIG += c++17

QMAKE_CXXFLAGS += -Werror

unix:DEFINES += POSIX
win32:DEFINES += WIN32

win32:QMAKE_LFLAGS +=  -Wl,--no-undefined --enable-runtime-pseudo-reloc 