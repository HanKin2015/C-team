#-------------------------------------------------
#
# Project created by QtCreator 2017-10-18T14:05:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HappyTogether
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog.cpp \
    registerdialog.cpp \
    detaildialog.cpp \
    personaldatadialog.cpp \
    globalvariable.cpp \
    client/session_c.cpp \
    client/socket_packet.cpp \
    client/socket_stream.cpp \
    client/UserClient.cpp \
    client/utils.cpp \
    base64.cpp \
    iniparser.cpp \
    receivemessagedialog.cpp \
    sendmessagedialog.cpp \
    spacedialog.cpp \
    retrievepwddialog.cpp \
    activitydialog.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    registerdialog.h \
    detaildialog.h \
    personaldatadialog.h \
    globalvariable.h \
    client/p_debug.h \
    client/request_reply.h \
    client/session_c.h \
    client/socket_packet.h \
    client/socket_stream.h \
    client/UserClient.h \
    client/utils.h \
    client/ConnectToMysql/SQLStruct.h \
    base64.h \
    iniparser.h \
    receivemessagedialog.h \
    sendmessagedialog.h \
    spacedialog.h \
    retrievepwddialog.h \
    activitydialog.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    registerdialog.ui \
    detaildialog.ui \
    personaldatadialog.ui \
    messagedialog.ui \
    sendmessagedialog.ui \
    spacedialog.ui \
    retrievepwddialog.ui \
    activitydialog.ui

RC_ICONS = images/HappyTogether.ico
QT += core gui
LIBS += -lpthread libwsock32 libws2_32

DEFINES-= UNICODE
