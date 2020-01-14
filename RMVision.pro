TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_CXXFLAGS += -std=gnu++11


INCLUDEPATH += -I/usr/local/include/opencv \
               -I/usr/local/include

LIBS += `pkg-config --libs opencv` \
    /usr/lib/x86_64-linux-gnu/libpthread.so

SOURCES += main.cpp \
    serial.cpp \
    #RuneDetector.cpp \
    #RuneResFilter.cpp \
    ArmorDetector.cpp \
    Predictor.cpp \
    ImageConsProd.cpp \
    RemoteController.cpp \
    AngleSolver.cpp \
    RMVideoCapture.cpp

HEADERS += \
    serial.h \
    cmdline.h \
    #RuneDetector.hpp \
    RuneResFilter.hpp \
    Settings.hpp \
    ArmorDetector.hpp \
    Predictor.hpp \
    ImageConsProd.hpp \
    RemoteController.hpp \
    AngleSolver.hpp \
    RMVideoCapture.hpp \
    LedController.hpp

