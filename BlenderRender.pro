QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    about.h \
    mainwindow.h

FORMS += \
    about.ui \
    mainwindow.ui

TRANSLATIONS += \
    Translations/BlenderRender_fr_FR.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Res/Icons.qrc \
    Translations/Translations.qrc

DISTFILES += \
    Res/Icons/Bitmaps/Diaspora.png \
    Res/Icons/Bitmaps/DownArrow.png \
    Res/Icons/Bitmaps/GitHub-Mark-Light-64px.png \
    Res/Icons/Bitmaps/Misskey_Light.png \
    Res/Icons/Bitmaps/Moins.png \
    Res/Icons/Bitmaps/TwitterLight.png \
    Res/Icons/Bitmaps/UpArrow.png \
    Res/Icons/Bitmaps/blenderLight.png \
    Res/Icons/Vertors/Diaspora-asterisk.svg \
    Res/Icons/Vertors/MenuLight.svg \
    Res/Icons/Vertors/TwitterLight.svg \
    Res/Icons/Vertors/blenderLight.svg \
    Res/Stylesheet_Default.qss \
    Res/Themes/Stylesheet_Default.qss
