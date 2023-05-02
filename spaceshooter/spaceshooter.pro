TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        game.cpp \
        inimigos.cpp \
        main.cpp \
        nave.cpp

win32: LIBS += -L$$PWD/../../Downloads/SDL2-2.0.12/lib/x64/ -lSDL2

INCLUDEPATH += $$PWD/../../Downloads/SDL2-2.0.12/include
DEPENDPATH += $$PWD/../../Downloads/SDL2-2.0.12/include

HEADERS +=\
    game.h \
    inimigos.h \
    nave.h

win32: LIBS += -L$$PWD/../../Downloads/SDL2_ttf-2.0.15/lib/x64/ -lSDL2_ttf

INCLUDEPATH += $$PWD/../../Downloads/SDL2_ttf-2.0.15/include
DEPENDPATH += $$PWD/../../Downloads/SDL2_ttf-2.0.15/include
