include("src/SCodes.pri")

QT += quick network

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        checkpointmodel.cpp \
        connectioncontroller.cpp \
        main.cpp \
        statemodel.cpp

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

android {
    DISTFILES += \
        android/AndroidManifest.xml \
        android/build.gradle \
        android/gradle/wrapper/gradle-wrapper.jar \
        android/gradle/wrapper/gradle-wrapper.properties \
        android/gradlew \
        android/gradlew.bat \
        android/res/values/libs.xml

    ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

    ANDROID_ABIS = armeabi-v7a
}

DISTFILES += \
    PageLogin.qml \
    PageSelectCheckpoint.qml \
    ScannerOverlay.qml \
    SimplePage.qml \

HEADERS += \
    checkpointmodel.h \
    connectioncontroller.h \
    statemodel.h
