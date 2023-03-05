QT       += core gui
CONFIG += c++17

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TARGET = Chapter_1

TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    mytask.cpp

HEADERS += \
    mainwindow.h \
    mytask.h

FORMS += \
    mainwindow.ui \
    mytask.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
