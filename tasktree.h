#ifndef TASKTREE_H
#define TASKTREE_H

#include <QObject>
#include <QStandardItem>

class TaskTree : public QObject
{
    Q_OBJECT
public:
    explicit TaskTree(QObject *parent = 0);
    TaskTree(QStandardItemModel *root);
    Q_INVOKABLE int sampleFunction();
    QStandardItem* findRecursive(const QStandardItemModel &tree, const QString &taskId);
    Q_INVOKABLE int nestingLevel(const QString &taskId);
    QList<QString> toPlainList();
signals:

public slots:
private:
    QStandardItem* findRecursiveChild(const QStandardItem &root, const QString &taskId);
    QStandardItemModel* tree;
    void addChildItems(QList<QString> &plainList, QStandardItem* item);
};

#endif // TASKTREE_H
