#include "taskidtree.h"

TaskIdTree::TaskIdTree(QObject *parent) :
    QObject(parent)
{
}

QString TaskIdTree::plainText()
{
    return plainText(0);
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

