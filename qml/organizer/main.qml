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
                    var modelData = display
                    var taskId = modelData
                    var nestingLevel = taskTree.nestingLevel(taskId)
                    x = 50 + leftMargin * nestingLevel
                }
                text: {
                    var modelData = display
                    "<b>" + "task " + modelData + "</b>"
                }
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.debug("click")
                    console.debug("current index: " + index)
                    if (previouslySelectedTaskIndex == -1) {
                        taskDelegateText.color = "red";
                        previouslySelectedTextBlock = taskDelegateText
                        previouslySelectedTaskIndex = index
                    } else {
                        previouslySelectedTextBlock.color = "black"
                        taskDelegateText.color = "red"
                        previouslySelectedTextBlock = taskDelegateText
                        previouslySelectedTaskIndex = index
                    }
                }
            }
            Keys.onRightPressed: {
                console.debug("Key 'right' pressed")
                if (previouslySelectedTaskIndex == -1) {
                    console.debug("There is not selected task. Do nothing.")
                } else {
                    var newTaskId = "abcdefg"
                    var selectedIndex = previouslySelectedTaskIndex
                    console.log("selected index: " + selectedIndex)
                    var whereToInsert = taskTree.byPlainIndex(selectedIndex)
                    console.log("where to insert: " + whereToInsert)
                    taskTree.insert(newTaskId, whereToInsert)
                    taskIdModel.insert(selectedIndex + 1, newTaskId)
                }
            }
        }
    }

    ListView {
        id: taskList
        anchors.fill: parent
        model: taskIdModel
        delegate: taskDelegate
        focus: true
    }
}


