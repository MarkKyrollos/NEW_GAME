QT       += core gui \
        multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    character.cpp \
    enemy.cpp \
    game.cpp \
    main.cpp \
    main_menu.cpp \
    mainwindow.cpp \
    major.cpp \
    minor.cpp \
    player.cpp \
    projectile.cpp

HEADERS += \
    character.h \
    enemy.h \
    game.h \
    main_menu.h \
    mainwindow.h \
    major.h \
    minor.h \
    player.h \
    projectile.h

FORMS += \
    main_menu.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc \
    sound.qrc

DISTFILES += \
    ../../doom.mp3
