#ifndef TASKTREE_H
#define TASKTREE_H

#include <QObject>
#include <QStandardItem>
#include <QQmlContext>

class TaskTree : public QObject
{
    Q_OBJECT
public:
    explicit TaskTree(QObject *parent = 0);
    void setRootContext(QQmlContext* context);
    TaskTree(QStandardItemModel *root);
    Q_INVOKABLE int sampleFunction();
    QStandardItem* findRecursive(const QStandardItemModel &tree, const QString &taskId);
    Q_INVOKABLE int nestingLevel(const QString &taskId);
    QList<QString> toPlainList();
    Q_INVOKABLE void insert(const QString &what, const QString &where);
    Q_INVOKABLE void update();
    Q_INVOKABLE QString byPlainIndex(int index);
signals:

public slots:
private:
    QStandardItem* findRecursiveChild(const QStandardItem &root, const QString &taskId);
    QStandardItemModel* tree;
    void addChildItems(QList<QString> &plainList, QStandardItem* item);
    QQmlContext* context;
};

#endif // TASKTREE_H
