TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_CXXFLAGS += -std=gnu++11 \
                -DSHOW_DEBUG_IMG \
                -DCOUT_LOG


INCLUDEPATH += -I/usr/local/include/opencv \
               -I/usr/local/include

LIBS += `pkg-config --libs opencv` \
         -pthread

SOURCES += ./src/*

HEADERS += ./include/*

