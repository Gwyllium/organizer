#include "alltests.h"

#include "tests/testtree.h"
#include "tests/models/testtaskidlistmodel_data.h"
#include "tests/models/testtaskidlistmodel_rowcount.h"
#include "tests/models/testtaskidlistmodel_toplainlist.h"
#include "tests/models/testtaskidlistmodel_insert.h"
#include "tests/storage/TaskIdTree/test_taskidtree_plaintext.h"
#include "tests/storage/TaskIdTree/test_taskidtree_after.h"
#include "tests/storage/TaskIdTree/test_taskidtree_plainlist.h"
#include "tests/domain/Task/testtask_all.h"
#include "tests/domain/DiaryRecord/testdiaryrecord_all.h"
#include "tests/storage/TaskIdTree/test_taskidtree_nestinglevel.h"

void runAllTests() {
    qDebug() << "Running all tests started...";

    int argc = 0;
    char** argv = NULL;
    QTest::qExec(new TestTree, argc, argv);
    QTest::qExec(new TestTaskIdListModel_data, argc, argv);
    QTest::qExec(new TestTaskIdListModel_rowCount, argc, argv);
    QTest::qExec(new TestTaskIdListModel_toPlainList, argc, argv);
    QTest::qExec(new TestTaskIdListModel_insert, argc, argv);
    QTest::qExec(new Test_TaskIdTree_plainText, argc, argv);
    QTest::qExec(new Test_TaskIdTree_after, argc, argv);
    QTest::qExec(new Test_TaskIdTree_plainList, argc, argv);
    QTest::qExec(new TestTask_all, argc, argv);
    QTest::qExec(new TestDiaryRecord_all, argc, argv);
    QTest::qExec(new Test_TaskIdTree_nestingLevel, argc, argv);

    qDebug() << "Running all tests finished...";
}
