TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    bisection.cpp \
    test_bisect.cpp \
    newton.cpp \
    test_newton.cpp

HEADERS += \
    fcn.hpp

