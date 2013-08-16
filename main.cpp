#include <QtGui/QGuiApplication>
#include <QObject>
#include <QQuickItem>
#include <QQmlContext>
#include <QQmlContext>
#include "qtquick2applicationviewer.h"
#include "testtask.h"
#include "testdiarryrecord.h"
#include "tests/testtree.h"
#include "tests/testtasktree_findrecursive.h"
#include "tests/testtasktree_nestinglevel.h"
#include "tests/testtasktree_toplainlist.h"
#include "tests/testtastktree_insert.h"
#include "tasktree.h"
#include <QStringListModel>
#include <QStringList>

int main(int argc, char *argv[])
{
    QTest::qExec(new TestTask, argc, argv);
    QTest::qExec(new TestDiarryRecord, argc, argv);
    QTest::qExec(new TestTree, argc, argv);
    QTest::qExec(new TestTaskTree_findRecursive, argc, argv);
    QTest::qExec(new TestTaskTree_nestingLevel, argc, argv);
    QTest::qExec(new TestTaskTree_toPlainList, argc, argv);
    QTest::qExec(new TestTastkTree_insert, argc, argv);

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

   // QStringList taskIdsList = taskTree->toPlainList();
   // viewer.rootContext()->setContextProperty("taskModel", QVariant::fromValue(taskIdsList));

    viewer.setMainQmlFile(QStringLiteral("qml/organizer/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
