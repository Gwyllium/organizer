#include <QtGui/QGuiApplication>
#include <QObject>
#include <QQuickItem>
#include <QQmlContext>
#include <QQmlContext>
#include "qtquick2applicationviewer.h"
#include "testtask.h"
#include "testdiarryrecord.h"
#include "tests/testtree.h"
#include "tasktree.h"
#include <QStringListModel>
#include <QStringList>

int main(int argc, char *argv[])
{
    QTest::qExec(new TestTask, argc, argv);
    QTest::qExec(new TestDiarryRecord, argc, argv);
    QTest::qExec(new TestTree, argc, argv);

    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;
    viewer.rootContext()->setContextProperty("taskTree", new TaskTree());

    QStringList taskIdsList = QStringList();
    taskIdsList.append("0");
    taskIdsList.append("1");
    taskIdsList.append("2");
    taskIdsList.append("3");
    taskIdsList.append("4");

    viewer.rootContext()->setContextProperty("taskModel", QVariant::fromValue(taskIdsList));


    viewer.setMainQmlFile(QStringLiteral("qml/organizer/main.qml"));
    viewer.showExpanded();



    return app.exec();
}
