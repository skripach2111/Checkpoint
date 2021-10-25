QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accessmodel.cpp \
    accountmodel.cpp \
    authorizationmodel.cpp \
    checkpointmodel.cpp \
    databasemodule.cpp \
    main.cpp \
    mainwindow.cpp \
    positionmodel.cpp \
    privilegemodel.cpp \
    statemodel.cpp \
    workermodel.cpp

HEADERS += \
    accessmodel.h \
    accountmodel.h \
    authorizationmodel.h \
    checkpointmodel.h \
    databasemodule.h \
    mainwindow.h \
    positionmodel.h \
    privilegemodel.h \
    statemodel.h \
    workermodel.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    Checkpoint_Desktop_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#LIBS += /libqsqlmysql.so -l
