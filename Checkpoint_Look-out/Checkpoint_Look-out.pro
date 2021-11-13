QT += quick sql

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../Checkpoint_Desktop/accessfiltermodel.cpp \
        ../Checkpoint_Desktop/accountfiltermodel.cpp \
        ../Checkpoint_Desktop/authorizationfiltermodel.cpp \
        ../Checkpoint_Desktop/checkpointfiltermodel.cpp \
        ../Checkpoint_Desktop/modelforcombobox.cpp \
        ../Checkpoint_Desktop/positionfiltermodel.cpp \
        ../Checkpoint_Desktop/statemodel.cpp \
        ../Checkpoint_Desktop/workerfiltermodel.cpp \
        databasemodule.cpp \
        main.cpp

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
    ../Checkpoint_Desktop/accessfiltermodel.h \
    ../Checkpoint_Desktop/accountfiltermodel.h \
    ../Checkpoint_Desktop/authorizationfiltermodel.h \
    ../Checkpoint_Desktop/checkpointfiltermodel.h \
    ../Checkpoint_Desktop/modelforcombobox.h \
    ../Checkpoint_Desktop/positionfiltermodel.h \
    ../Checkpoint_Desktop/statemodel.h \
    ../Checkpoint_Desktop/workerfiltermodel.h \
    databasemodule.h
