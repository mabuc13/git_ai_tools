#-------------------------------------------------
#
# Project created by QtCreator 2016-03-15T10:40:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ludo
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    game.cpp \
    ludo_player_random.cpp \
    smart_ludo_player.cpp \
    ludo_player.cpp \
    geneticludoevolv.cpp

HEADERS  += dialog.h \
    game.h \
    positions_and_dice.h \
    ludo_player_random.h \
    smart_ludo_player.h \
    ludo_player.h \
    geneticludoevolv.h

FORMS    += dialog.ui

QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Wunused
