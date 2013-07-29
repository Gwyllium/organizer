import QtQuick 2.0

Item {
    id: taskListMain
    width: 300
    height: 200
    property int previouslySelectedTaskIndex: -1
    property QtObject previouslySelectedTextBlock: null
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
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.debug("click")
                    if (previouslySelectedTaskIndex == -1) {
                        taskDelegateText.color = "red";
                        previouslySelectedTextBlock = taskDelegateText
                        previouslySelectedTaskIndex = taskList.currentIndex
                    } else {
                        previouslySelectedTextBlock.color = "black"
                        taskDelegateText.color = "red"
                        previouslySelectedTaskIndex = taskList.currentIndex
                        previouslySelectedTextBlock = taskDelegateText
                    }
                }
            }
            Keys.onRightPressed:  {
                console.debug("Key 'right' pressed")
                if (previouslySelectedTaskIndex == -1) {
                    console.debug("There is not selected task. Do nothing.")
                } else {
                    var newTaskId = "555"
                    var where = previouslySelectedTaskIndex.toString();
                    taskTree.insert(where, newTaskId)
                    console.debug("task model " + taskModel)
                    //taskModel.insert(previouslySelectedTaskIndex, newTaskId)
                    taskList.update();
                }
            }
        }
    }

    ListView {
        id: taskList
        anchors.fill: parent
        model: taskModel
        delegate: taskDelegate
        focus: true
    }
}


