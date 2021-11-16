QT += quick sql

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        accessfiltermodel.cpp \
        accessmodel.cpp \
        accountfiltermodel.cpp \
        accountmodel.cpp \
        authorizationfiltermodel.cpp \
        authorizationmodel.cpp \
        checkpointfiltermodel.cpp \
        checkpointmodel.cpp \
        databasemodule.cpp \
        main.cpp \
        modelforcombobox.cpp \
        positionfiltermodel.cpp \
        positionmodel.cpp \
        privilegemodel.cpp \
        statemodel.cpp \
        workerfiltermodel.cpp \
        workermodel.cpp

RESOURCES += qml.qrc

TRANSLATIONS += \
    Checkpoint_Look-out_ru_UA.ts
CONFIG += lrelease
CONFIG += embed_translations

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    PageLogin.qml \
    PageSelectCheckpoint.qml \
    SimplePage.qml

HEADERS += \
    accessfiltermodel.h \
    accessmodel.h \
    accountfiltermodel.h \
    accountmodel.h \
    authorizationfiltermodel.h \
    authorizationmodel.h \
    checkpointfiltermodel.h \
    checkpointmodel.h \
    databasemodule.h \
    modelforcombobox.h \
    positionfiltermodel.h \
    positionmodel.h \
    privilegemodel.h \
    statemodel.h \
    workerfiltermodel.h \
    workermodel.h

SUBDIRS += \
    ../../../Qt/5.15.2/Src/qtbase/src/plugins/sqldrivers/mysql/mysql.pro
