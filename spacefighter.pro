TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "C:/SFML-2.5.1/include"
LIBS += -L"C:/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-graphics-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-graphics -lsfml-system -lsfml-window
}

SOURCES += \
        src/bullet.cpp \
        src/button.cpp \
        src/enemy.cpp \
        src/game.cpp \
        src/main.cpp \
        src/menu.cpp \
        src/menustate.cpp \
        src/pausestate.cpp \
        src/player.cpp \
        src/playingstate.cpp \
        src/ship.cpp

HEADERS += \
    src/bullet.h \
    src/button.h \
    src/enemy.h \
    src/game.h \
    src/gamestate.h \
    src/menu.h \
    src/menustate.h \
    src/pausestate.h \
    src/player.h \
    src/playingstate.h \
    src/ship.h

DISTFILES += \
    README.md
