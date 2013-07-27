import QtQuick 2.0

Item {
    id: taskListMain
    width: 300
    height: 200
    property int selectedTaskId: -1
    property int leftMargin: 100



    Component {
        id: taskDelegate
        Rectangle {
            id: taskRectangle
            height: 50
            width: parent.width
            Text {
                id: taskDelegateText
                anchors.verticalCenter: parent.verticalCenter
                x: {
                    console.debug("item data: " + modelData)
                    var taskId = parseInt(modelData)
                    var nestingLevel = taskTree.nestingLevel(taskId)
                    console.debug("nesting level: " + nestingLevel)
                    x = 50 + leftMargin * nestingLevel
                    console.debug("all tasks " + allTasks)
                }
                text: "<b>" + "task " + parseInt(modelData) + "</b>"
            }
        }
    }

    ListView {
        id: taskList
        anchors.fill: parent
        model: taskModel
        delegate: taskDelegate
    }
}


