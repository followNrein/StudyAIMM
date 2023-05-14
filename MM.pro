TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += C++11


SOURCES += main.cpp \
    function.cpp

include(deployment.pri)
qtcAddDeployment()

DISTFILES +=

HEADERS += \
    function.h

