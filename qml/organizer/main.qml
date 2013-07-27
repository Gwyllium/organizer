import QtQuick 2.0

Item {
    id: taskListMain
    width: 300
    height: 200
    property int selectedTaskId: -1

    property variant tree : {
        0: {
            1:-1,
            2:-1
        }
    }



    Component {
        id: taskDelegate
        Rectangle {
            id: taskRectangle
            height: 50
            width: parent.width
            Text {
                id: taskDelegateText
                anchors.verticalCenter: parent.verticalCenter
                //anchors.horizontalCenter: parent.horizontalCenter
                x: {
                    console.debug("item data: " + modelData)
                    var taskId = parseInt(modelData)
                    if (taskId === 1 || taskId === 2) {
                        x = 200
                    } else {
                        x = 100
                    }
                }

                text: "<b>" + "task " + parseInt(modelData) + "</b>"
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.debug("clicked")
                    console.log("tree: " + tree)
                    selectedTaskId = parseInt(modelData)
                    var selectedTaskChildren = tree[selectedTaskId]
//                    var selectedTask
//                    if ( selectedTask.expanded ) {
//                        console.log("Selected task is expanded.")
//                        selectedTask.expanded = false
//                        for(var childTaskId in selectedTaskChildren) {
//                            console.debug("child: " + childTaskId)
//                            taskList.currentIndex = childTaskId
//                            var childItem = taskList.currentItem
//                            childItem.visible = false
//                            childItem.height = 0
//                        }
//                    } else {
//                        console.log("Selected task is collapsed.")
//                        selectedTask.expanded = true
//                        for(childTaskId in selectedTaskChildren) {
//                            console.debug("child: " + childTaskId)
//                            taskList.currentIndex = childTaskId
//                            childItem = taskList.currentItem
//                            childItem.visible = true
//                            childItem.height = 50
//                        }
//                    }

                }
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


