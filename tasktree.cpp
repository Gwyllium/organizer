#include "tasktree.h"
#include "QDebug"


TaskTree::TaskTree(QObject *parent) :
    QObject(parent)
{
}

void TaskTree::setRootContext(QQmlContext *context)
{
    this->context = context;
}

TaskTree::TaskTree(QStandardItemModel* root)
{
    this->tree = root;
}

int TaskTree::sampleFunction()
{
    return 1;
}

QStandardItem *TaskTree::findRecursive(const QStandardItemModel &tree, const QString &taskId)
{
    QList<QStandardItem*> foundAtFirstLevel = tree.findItems(taskId);
    if (!foundAtFirstLevel.isEmpty()) {
        return foundAtFirstLevel[0];
    }
    for(int row = 0; row < tree.rowCount(); row++) {
        QStandardItem* currentChild = tree.item(row, 0);
        QStandardItem* found = findRecursiveChild(*currentChild, taskId);
        if (found != NULL) {
            return found;
        }
    }
    return NULL;
}

int TaskTree::nestingLevel(const QString &taskId)
{
    QStandardItem* item =findRecursive(*tree, taskId);
    if (item == NULL) {
        return -1;
    }
    int nestingLevel = 0;
    while (item->parent() != NULL) {
        nestingLevel += 1;
        item = item->parent();
    }
    return nestingLevel;
}

void TaskTree::addChildItems(QList<QString> &plainList, QStandardItem* item)
{
    for(int row = 0; row < item->rowCount(); row++) {
        QStandardItem* currentItem = item->child(row, 0);
        plainList << currentItem->text();
        addChildItems(plainList, currentItem);
    }
}

QList<QString> TaskTree::toPlainList()
{
    QList<QString> plainList;
    for(int row = 0; row < tree->rowCount(); row++) {
        QStandardItem* currentItem = tree->item(row, 0);
        plainList << currentItem->text();
        addChildItems(plainList, currentItem);
    }
    return plainList;
}

void TaskTree::insert(const QString &what, const QString &where)
{
    QStandardItem* whereItem = findRecursive(*tree, where);
    qDebug() << "where item " << whereItem;
    if (whereItem == NULL) {
        return;
    }
    QStandardItem* whatItem = new QStandardItem(what);
    whereItem->insertRow(0, whatItem);
}

void TaskTree::update()
{
    QStringList taskIdsList = this->toPlainList();
    context->setContextProperty("taskModel", QVariant::fromValue(taskIdsList));

}

QString TaskTree::byPlainIndex(int index)
{
    return this->toPlainList()[index];
}

QStandardItem *TaskTree::findRecursiveChild(const QStandardItem &root, const QString &taskId)
{
    for(int row = 0; row < root.rowCount(); row++) {
        QStandardItem* currentChild = root.child(row, 0);
        if (currentChild->text() == taskId) {
            return currentChild;
        } else {
            if (currentChild->hasChildren()) {
                QStandardItem* found = findRecursiveChild(*currentChild, taskId);
                if (found != NULL) {
                    return found;
                }
            }
        }
    }
    return NULL;
}
