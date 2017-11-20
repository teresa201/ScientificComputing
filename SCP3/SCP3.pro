TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    matrix.cpp \
    test_Newton_test.cpp \
    Lagrange.cpp \
    test_Lagrange.cpp \
    interpolation_degree.cpp \
    runge_uniform.cpp

HEADERS += \
    matrix.hpp

