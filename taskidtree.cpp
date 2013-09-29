#include "taskidtree.h"

TaskIdTree::TaskIdTree(QObject *parent) :
    QObject(parent)
{
}

QString TaskIdTree::plainText(int nestingLevel)
{
    QString fullText;
    QString nestingLevelAsString;
    QString formatterStub;
    nestingLevelAsString = formatterStub.sprintf("%d", nestingLevel);
    for(int i = 0; i < m_children.length(); i++) {
        fullText += "[" + m_children[i]->m_value + "->" + nestingLevelAsString + "]";
        fullText += m_children[i]->plainText(nestingLevel + 1);
    }
    return fullText;
}

QString TaskIdTree::plainText()
{
    return plainText(0);
}

QList<QString> TaskIdTree::plainList()
{
    QList<QString> result;
    plainList(result);
    return result;
}

void TaskIdTree::plainList(QList<QString> &allIds)
{
    for(int i = 0; i < m_children.length(); i++) {
        allIds << m_children[i]->m_value;
        m_children[i]->plainList(allIds);
    }
}

void TaskIdTree::add(const QString &taskId)
{
    TaskIdTree *newChild = new TaskIdTree();
    newChild->m_value=taskId;
    m_children.append(newChild);
}

TaskIdTree *TaskIdTree::after(int index)
{
    if (m_children.length() == 0) {
        return NULL;
    }
    return m_children[index];
}

int TaskIdTree::nestingLevel(const QString &taskId)
{
    return -1;
}

