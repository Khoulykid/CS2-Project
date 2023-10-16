QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bigboss.cpp \
    bigboss_weapon.cpp \
    bullet.cpp \
    cannon.cpp \
    coinbar.cpp \
    coinobject.cpp \
    enemy1.cpp \
    enemy1_weapon.cpp \
    enemy2.cpp \
    enemy2_weapon.cpp \
    form.cpp \
    game.cpp \
    healthbar.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    player_weapon.cpp \
    store.cpp \
    win.cpp

HEADERS += \
    bigboss.h \
    bigboss_weapon.h \
    bullet.h \
    cannon.h \
    coinbar.h \
    coinobject.h \
    enemy1.h \
    enemy1_weapon.h \
    enemy2.h \
    enemy2_weapon.h \
    form.h \
    game.h \
    healthbar.h \
    mainwindow.h \
    player.h \
    player_weapon.h \
    store.h \
    win.h

FORMS += \
    form.ui \
    mainwindow.ui \
    store.ui \
    win.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
