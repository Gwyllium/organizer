#include <QtGui/QGuiApplication>
#include <QObject>
#include <QQuickItem>
#include <QQmlContext>
#include <QQmlContext>
#include "qtquick2applicationviewer.h"
#include "tasktree.h"
#include "taskidlistmodel.h"
#include <QStringListModel>
#include <QStringList>
#include <QDebug>
#include "tests/alltests.h"

int main(int argc, char *argv[])
{
    runAllTests();

    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;

    QStandardItemModel* tree = new QStandardItemModel();
    QList<QStandardItem*> firstLevel;
    firstLevel << new QStandardItem("0");
    firstLevel << new QStandardItem("1");
    firstLevel << new QStandardItem("2");
    QList<QStandardItem*> secondLevelA;
    secondLevelA << new QStandardItem("3");
    secondLevelA << new QStandardItem("4");
    QList<QStandardItem*> secondLevelB;
    secondLevelB << new QStandardItem("5");
    secondLevelB << new QStandardItem("6");
    secondLevelB << new QStandardItem("7");
    QList<QStandardItem*> thirdLevel;
    thirdLevel << new QStandardItem("8");
    thirdLevel << new QStandardItem("9");
    thirdLevel << new QStandardItem("10");
    secondLevelA[1]->appendColumn(thirdLevel);
    firstLevel[0]->appendColumn(secondLevelA);
    firstLevel[2]->appendColumn(secondLevelB);
    tree->appendColumn(firstLevel);
    TaskTree *taskTree = new TaskTree(tree);
    taskTree->setRootContext(viewer.rootContext());
    viewer.rootContext()->setContextProperty("taskTree", taskTree);

    TaskIdListModel *taskIdModel = new TaskIdListModel();
    QStringList taskIdsList = taskTree->toPlainList();
    for(int i = 0; i < taskIdsList.count(); i++) {
        QString currentId = taskIdsList[i];
        taskIdModel->add(currentId);
    }
   // qDebug() << taskIdModel->toPlainList();
    viewer.rootContext()->setContextProperty("taskIdModel", taskIdModel);

    viewer.setMainQmlFile(QStringLiteral("qml/organizer/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
