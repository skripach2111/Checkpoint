/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#include <SBarcodeFilter.h>
#include <SBarcodeGenerator.h>

void qml_register_types_com_scythestudio_scodes()
{
    qmlRegisterTypesAndRevisions<SBarcodeFilter>("com.scythestudio.scodes", 1);
    qmlRegisterTypesAndRevisions<SBarcodeGenerator>("com.scythestudio.scodes", 1);
    qmlRegisterModule("com.scythestudio.scodes", 1, 0);
}

static const QQmlModuleRegistration registration("com.scythestudio.scodes", 1, qml_register_types_com_scythestudio_scodes);
