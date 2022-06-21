#include <QCoreApplication>

#include "appcore.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    AppCore core;

    core.slotStart();

    return a.exec();
}
