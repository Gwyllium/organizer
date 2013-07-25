import QtQuick 2.0

Item {
    id: taskListMain
    width: 300
    height: 200
    property int selectedTaskId: -1



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
                   if (taskId == 2) {
                       x = 200
                   } else {
                       x = 100
                   }
               }

               text: "<b>" + name + "</b>"
           }
           MouseArea {
               anchors.fill: parent
               onClicked: {
                   console.log("clicked")
                   selectedTaskId = taskId

                   if (selectedTaskId == 1) {
                       taskList.currentIndex = selectedTaskId
                       taskList.currentItem.visible = false
                       taskList.currentItem.height = 0
                   }

                   //taskList.currentIndex = selectedtaskId - 1
//                   taskList.currentItem.visible = false
//                   taskList.currentItem.height = 0
               }
           }
//           states: [
//                State {
//                   name: "selected"
//                   when: (taskId==selectedtaskId)
//                   //when: (1 == selectedtaskId)
//                   //PropertyChanges {target: taskRectangle; color: "red"}
//                   PropertyChanges {
//                       target: taskRectangle; visible: false; height: 0
//                   }
//               }
//           ]
        }
    }

    ListView {
        id: taskList
        anchors.fill: parent
        model: taskModel
        delegate: taskDelegate
    }

    ListModel {
            id: taskModel
            ListElement {
                taskId: 1
                name: "task 1"
            }
            ListElement {
                taskId: 2
                name: "task 2"
            }
            ListElement {
                taskId: 3
                name: "task 3"
            }
            ListElement {
                taskId: 4
                name: "task 4"
            }
            ListElement {
                taskId: 5
                name: "task 5"
            }
        }
}


