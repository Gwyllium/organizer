#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include "testtask.h"
#include "testdiarryrecord.h"


int main(int argc, char *argv[])
{
    QTest::qExec(new TestTask, argc, argv);
    QTest::qExec(new TestDiarryRecord, argc, argv);

    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/organizer/main.qml"));
    viewer.showExpanded();


    return app.exec();
}
