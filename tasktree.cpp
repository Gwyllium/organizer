#include "tasktree.h"

TaskTree::TaskTree(QObject *parent) :
    QObject(parent)
{
}

int TaskTree::sampleFunction()
{
    return 1;
}
