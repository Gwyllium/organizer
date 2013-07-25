#include <QtGui/QGuiApplication>
#include <QObject>
#include <QQuickItem>
#include <QQmlContext>
#include <QQmlContext>
#include "qtquick2applicationviewer.h"
#include "testtask.h"
#include "testdiarryrecord.h"
#include "tests/testtree.h"


int main(int argc, char *argv[])
{
    QTest::qExec(new TestTask, argc, argv);
    QTest::qExec(new TestDiarryRecord, argc, argv);
    QTest::qExec(new TestTree, argc, argv);

    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/organizer/main.qml"));
    viewer.showExpanded();

    QQuickItem *root = viewer.rootObject();
    qDebug() << root;
    QQuickItem *taskList = root->findChild<QQuickItem*>(QString("taskList"), Qt::FindDirectChildrenOnly);
    qDebug() << taskList;

    QQmlContext* context = viewer.rootContext();
    QVariant taskModel = context->property("taskModel");
    qDebug() << taskModel;


    return app.exec();
}
