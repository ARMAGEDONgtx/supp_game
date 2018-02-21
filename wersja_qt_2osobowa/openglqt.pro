#-------------------------------------------------
#
# Project created by QtCreator 2016-05-25T04:49:19
#
#-------------------------------------------------

QT       += core gui opengl network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = openglqt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cscenaqt.cpp \
    bielan_przeszkoda_1.cpp \
    boss.cpp \
    czlowiek.cpp \
    figura.cpp \
    figury.cpp \
    fizyka.cpp \
    funckje.cpp \
    gnom.cpp \
    gracz.cpp \
    pawlak_slupki.cpp \
    pawlak_wieze.cpp \
    pawlak_winda.cpp \
    przeszkoda.cpp \
    wrobel_dzialo.cpp \
    wrobel_gate.cpp \
    wrobel_kolec.cpp \
    wrobel_most.cpp \
    wrobel_przepasc.cpp \
    wrobel_przeszkoda_1.cpp \
    gameclient.cpp \
    webdlg.cpp

HEADERS  += mainwindow.h \
    cscenaqt.h \
    bielan_przeszkoda_1.h \
    boss.h \
    czlowiek.h \
    figura.h \
    figury.h \
    fizyka.h \
    funckje.h \
    gnom.h \
    gracz.h \
    pawlak_slupki.h \
    pawlak_wieze.h \
    pawlak_winda.h \
    przeszkoda.h \
    wrobel_dzialo.h \
    wrobel_gate.h \
    wrobel_kolec.h \
    wrobel_most.h \
    wrobel_przepasc.h \
    wrobel_przeszkoda_1.h \
    gameclient.h \
    ../Simple OpenGL Image Library/src/SOIL.h \
    webdlg.h

FORMS    += mainwindow.ui \
    webdlg.ui
LIBS += opengl32.lib
LIBS += -lGlu32



win32: LIBS += -L$$PWD/'../Simple OpenGL Image Library/projects/VC9/x64/Debug/' -lSOIL

INCLUDEPATH += $$PWD/'../Simple OpenGL Image Library/src'
DEPENDPATH += $$PWD/'../Simple OpenGL Image Library/src'

RESOURCES +=

DISTFILES += \
    textury/kaczmi_tex.bmp \
    textury/wiesia_tex.bmp \
    textury/background.jpg \
    textury/bricks.jpg \
    textury/castle.jpg \
    textury/eyes.jpg \
    textury/gate.jpg \
    textury/gnom.jpg \
    textury/grass1.jpg \
    textury/grucha.jpg \
    textury/joker.jpg \
    textury/kaczmi.jpg \
    textury/kevlar.jpg \
    textury/ladder.jpg \
    textury/m_face.jpg \
    textury/m_face2.jpg \
    textury/mario.jpg \
    textury/metallic.jpg \
    textury/mush.jpg \
    textury/ork.jpg \
    textury/shirt.jpg \
    textury/shrek.jpg \
    textury/terrorist.jpg \
    textury/tlo.jpg \
    textury/wiesia.jpg \
    textury/winda.jpg \
    textury/helmet.png \
    textury/kaczmi_tex.png \
    textury/terrorist.png
