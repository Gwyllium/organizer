#include "alltests.h"

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
#include "tests/storage/TaskIdTree/test_taskidtree_plaintext.h"
#include "tests/storage/TaskIdTree/test_taskidtree_after.h"
#include "tests/storage/TaskIdTree/test_taskidtree_plainlist.h"

void runAllTests() {
    qDebug() << "Running all tests started...";

    int argc = 0;
    char** argv = NULL;
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
    QTest::qExec(new Test_TaskIdTree_plainText, argc, argv);
    QTest::qExec(new Test_TaskIdTree_after, argc, argv);
    QTest::qExec(new Test_TaskIdTree_plainList, argc, argv);

    qDebug() << "Running all tests finished...";
}
