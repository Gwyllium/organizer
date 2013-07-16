import QtQuick 2.0

Rectangle {
    width: 1024
    height: 768
    color: "#bbbbbb"
    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }

        Rectangle {
            id: rectangle1
            x: 0
            y: 0
            width: 76
            height: 768
            color: "#444444"
        }
    }
}

