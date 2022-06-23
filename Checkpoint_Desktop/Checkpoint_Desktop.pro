QT       += core gui sql printsupport qml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
    mainwindow.cpp \
    modelforcombobox.cpp \
    modelforprint.cpp \
    modelforprintcheckpoint.cpp \
    positionfiltermodel.cpp \
    positionmodel.cpp \
    privilegemodel.cpp \
    scaledpixmap.cpp \
    statemodel.cpp \
    workerfiltermodel.cpp \
    workermodel.cpp

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
    mainwindow.h \
    modelforcombobox.h \
    modelforprint.h \
    modelforprintcheckpoint.h \
    positionfiltermodel.h \
    positionmodel.h \
    privilegemodel.h \
    scaledpixmap.h \
    statemodel.h \
    workerfiltermodel.h \
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

# For Lime Report
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -llimereport
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -llimereport
else:unix: LIBS += -L$$PWD/lib/ -llimereport

INCLUDEPATH += $$PWD/lib/include
DEPENDPATH += $$PWD/lib/include


linux{
    #Link share lib to ../libs/limereport rpath
    QMAKE_LFLAGS += -Wl,--rpath=\\\$\$ORIGIN
    QMAKE_LFLAGS += -Wl,--rpath=\\\$\$ORIGIN/lib
#    QMAKE_LFLAGS += -Wl,--rpath=\\\$\$ORIGIN/../lib/
#    QMAKE_LFLAGS += -Wl,--rpath=\\\$\$ORIGIN/../lib/limereport/
#    QMAKE_LFLAGS += -Wl,--rpath=\\\$\$ORIGIN/../../lib/
    QMAKE_LFLAGS_RPATH += #. .. ./libs
}
