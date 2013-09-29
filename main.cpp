#include <QtGui/QGuiApplication>
#include <QObject>
#include <QQuickItem>
#include <QQmlContext>
#include <QQmlContext>
#include "qtquick2applicationviewer.h"
#include "taskidlistmodel.h"
#include <QStringListModel>
#include <QStringList>
#include <QDebug>
#include "taskidtree.h"
#include "tests/alltests.h"


int main(int argc, char *argv[])
{
    runAllTests();

    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;

    TaskIdTree* taskIdTree = new TaskIdTree();
    taskIdTree->add("task 0");
    taskIdTree->add("task 1");
    taskIdTree->add("task 2");
    taskIdTree->after(0)->add("task 3");
    taskIdTree->after(0)->add("task 4");
    taskIdTree->after(0)->after(1)->add("task 8");
    taskIdTree->after(0)->after(1)->add("task 9");
    taskIdTree->after(0)->after(1)->add("task 10");
    taskIdTree->after(2)->add("task 5");
    taskIdTree->after(2)->add("task 6");
    taskIdTree->after(2)->add("task 7");
    viewer.rootContext()->setContextProperty("taskIdTree", taskIdTree);
    TaskIdListModel *taskIdModel = new TaskIdListModel();
    QStringList taskIdsList = taskIdTree->plainList();
    for(int i = 0; i < taskIdsList.count(); i++) {
        QString currentId = taskIdsList[i];
        taskIdModel->add(currentId);
    }
    viewer.rootContext()->setContextProperty("taskIdModel", taskIdModel);

    viewer.setMainQmlFile(QStringLiteral("qml/organizer/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
