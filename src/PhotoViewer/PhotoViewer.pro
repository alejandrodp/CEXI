#-------------------------------------------------
#
# Project created by QtCreator 2018-03-14T23:14:12
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PhotoViewer
TEMPLATE = app

QMAKE_CXXFLAGS = -std=gnu++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    launcher.cpp \
    main.cpp \
    MemoryManager/DiskAccess.cpp \
    MemoryManager/MemoryManager.cpp \
    MemoryManager/MMU.cpp \
    structures/Lists/SimpleList.cpp \
    MemoryViewer.cpp \
    socketmanager.cpp \
    TcpSocket.cpp \
    OperationsManager.cpp

HEADERS += \
    MemoryManager/DiskAccess.h \
    MemoryManager/MemoryManager.h \
    MemoryManager/MMU.h \
    structures/Lists/SimpleList.h \
    MemoryViewer.h \
    launcher.h \
    socketmanager.h \
    TcpSocket.h \
    OperationsManager.h

FORMS += \
    launcher.ui \
    MemoryViewer.ui
