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
#include "tests/models/testtaskidlistmodel_data.h"
#include "tests/models/testtaskidlistmodel_rowcount.h"
#include "tests/models/testtaskidlistmodel_toplainlist.h"
#include "tests/models/testtaskidlistmodel_insert.h"
#include "tests/testtasktree_byplainindex.h"
#include "tests/storage/TaskIdTree/test_plaintext.h"
#include "tasktree.h"
#include "taskidlistmodel.h"
#include <QStringListModel>
#include <QStringList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QTest::qExec(new TestTask, argc, argv);
    QTest::qExec(new TestDiarryRecord, argc, argv);
    QTest::qExec(new TestTree, argc, argv);
    QTest::qExec(new TestTaskTree_findRecursive, argc, argv);
    QTest::qExec(new TestTaskTree_nestingLevel, argc, argv);
    QTest::qExec(new TestTaskTree_toPlainList, argc, argv);
    QTest::qExec(new TestTastkTree_insert, argc, argv);
    QTest::qExec(new TestTaskIdListModel_data, argc, argv);
    QTest::qExec(new TestTaskIdListModel_rowCount, argc, argv);
    QTest::qExec(new TestTaskIdListModel_toPlainList, argc, argv);
    QTest::qExec(new TestTaskIdListModel_insert, argc, argv);
    QTest::qExec(new TestTaskTree_byPlainIndex, argc, argv);
    QTest::qExec(new Test_plainText, argc, argv);
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
    qDebug() << taskIdModel->toPlainList();
    viewer.rootContext()->setContextProperty("taskIdModel", taskIdModel);

    viewer.setMainQmlFile(QStringLiteral("qml/organizer/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
