#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include "tasktest.h"

int main(int argc, char *argv[])
{
    TaskTest();

    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/organizer/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
