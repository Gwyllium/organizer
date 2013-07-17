#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include "testtask.h"


int main(int argc, char *argv[])
{
    QTest::qExec(new TestTask, argc, argv);

    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/organizer/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
