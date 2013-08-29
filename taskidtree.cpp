#include "taskidtree.h"

TaskIdTree::TaskIdTree(QObject *parent) :
    QObject(parent)
{
}

QString TaskIdTree::plainText()
{
    QString fullText;
    for(int i = 0; i < m_items.length(); i++) {
        fullText += "[" + m_items[i] + ", " + "0]";
    }
    return fullText;
}

void TaskIdTree::add(const QString &taskId)
{
    m_items << taskId;
}
