import QtQuick 2.0

Rectangle {
    width: 640; height: 480

    Component {
        id: taskDelegate
        Item {
            id: wrapper
            width: parent.width; height: taskInfo.height
            Column {
                id: taskInfo
                Text {
                    text: '<b>' + name + '</b>'
                    color: wrapper.ListView.isCurrentItem ? "black" : "red"
                }
            }
        }
    }

    ListView {
        anchors.fill: parent
        model: TaskModel {}
        delegate: taskDelegate
        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
        focus: true
    }
}
