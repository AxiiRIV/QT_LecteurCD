QT       += core gui
QT += core gui multimedia
QT  +=core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    LecteurCD.cpp \
    cd.cpp \
    cellule.cpp \
    database.cpp \
    dialog.cpp \
    main.cpp \
    lecteurvue.cpp \
    sortieson.cpp \
    tiroircd.cpp \
    titre.cpp

HEADERS += \
    LecteurCD.h \
    cd.h \
    cellule.h \
    database.h \
    declarationsCommunes.h \
    declarationsCommunes.h \
    dialog.h \
    lecteurvue.h \
    sortieson.h \
    tiroircd.h \
    titre.h

FORMS += \
    dialog.ui \
    lecteurvue.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
