#-------------------------------------------------
#
# Project created by QtCreator 2012-03-22T11:23:28
#
#-------------------------------------------------

QT       +=
CONFIG   += console

TARGET = OpenCVMovementTracking
TEMPLATE = app


SOURCES += main.cpp \
    tracker.cpp \
    webcamtracker.cpp \
    trackviewer.cpp

HEADERS  += \
    tracker.h \
    webcamtracker.h \
    trackviewer.h

# You might need to adjust these to your build environment. Either way,
# you're gonna need to download the OpenCV superpack if you don't
# have it already.
#
# Change the version number (231) and compiler (vc10) where needed! Debug
# and release builds depend on different DLLs!
INCLUDEPATH += C:/opencv/build/include
CONFIG (debug, debug|release) {
    LIBS += -LC:/opencv/build/x86/vc10/lib -lopencv_core231d -lopencv_highgui231d -lopencv_objdetect231d -lopencv_imgproc231d
}
CONFIG (release, debug|release) {
    LIBS += -LC:/opencv/build/x86/vc10/lib -lopencv_core231 -lopencv_highgui231 -lopencv_objdetect231 -lopencv_imgproc231
}
