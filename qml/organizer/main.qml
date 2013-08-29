import QtQuick 2.0

Item {
    id: taskListMain
    width: 300
    height: 200

    property int previouslySelectedTaskIndex: -1
    property QtObject previouslySelectedTextBlock: null
    property int leftMargin: 100
    property int someProperty: 216

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
            //        console.debug("item data: " + modelData)
                    var taskId = modelData
              //      console.debug("task id: " + taskId)
                    var nestingLevel = taskTree.nestingLevel(taskId)
                //    console.debug("nesting level: " + nestingLevel)
                    x = 50 + leftMargin * nestingLevel
                  //  console.debug("all tasks " + allTasks)
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
                console.debug("some property: " + someProperty)
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

//    ListModel {
//        id: taskModel
//        ListElement {
//            modelData: "0"
//        }

//        ListElement {
//            modelData: "3"
//        }

//        ListElement {
//            modelData: "4"
//        }
//        ListElement {
//            modelData: "8"
//        }
//        ListElement {
//            modelData: "9"
//        }
//        ListElement {
//            modelData: "10"
//        }
//        ListElement {
//            modelData: "1"
//        }
//        ListElement {
//            modelData: "2"
//        }
//        ListElement {
//            modelData: "5"
//        }
//        ListElement {
//            modelData: "6"
//        }
//        ListElement {
//            modelData: "7"
//        }
//    }
}


