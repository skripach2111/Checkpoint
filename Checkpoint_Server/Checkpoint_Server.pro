QT -= gui
QT += sql network

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        accessfiltermodel.cpp \
        accessmodel.cpp \
        accountfiltermodel.cpp \
        accountmodel.cpp \
        appcore.cpp \
        authorizationfiltermodel.cpp \
        authorizationmodel.cpp \
        checkpointfiltermodel.cpp \
        checkpointmodel.cpp \
        databasemodule.cpp \
        main.cpp \
        modelforcombobox.cpp \
        modelforprint.cpp \
        positionfiltermodel.cpp \
        positionmodel.cpp \
        privilegemodel.cpp \
        statemodel.cpp \
        workerfiltermodel.cpp \
        workermodel.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    accessfiltermodel.h \
    accessmodel.h \
    accountfiltermodel.h \
    accountmodel.h \
    appcore.h \
    authorizationfiltermodel.h \
    authorizationmodel.h \
    checkpointfiltermodel.h \
    checkpointmodel.h \
    databasemodule.h \
    modelforcombobox.h \
    modelforprint.h \
    positionfiltermodel.h \
    positionmodel.h \
    privilegemodel.h \
    statemodel.h \
    workerfiltermodel.h \
    workermodel.h
