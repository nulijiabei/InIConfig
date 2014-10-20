TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    INIConfig.cpp \
    main.cpp

HEADERS += \
    INIConfig.h

QMAKE_CXXFLAGS += -std=c++11
