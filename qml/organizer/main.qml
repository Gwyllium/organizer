import QtQuick 2.0

// в qml-файле есть корневой элемент
// Item не отображается
Item {
    id: taskListMain
    width: 300
    height: 200

    property int previouslySelectedTaskIndex: -1
    property QtObject previouslySelectedTextBlock: null
    property int leftMargin: 100

    // Component - предоставляет базовую функциональность для работы с визуальными элементами.
    // Он содержит в себе подэлементы и код (обработчики).
    // Задается разметка компонента, а сами данные могут браться из некоторого источника
    // (в нашем случае это модель списка). А поскольку модель, разметка и обработчики определены внутри
    // одного и того же Item'а, то они "знают" друг о друге.
    Component {
        id: taskDelegate
        Rectangle {
            id: taskRectangle
            height: 50
            width: parent.width
            // здесь внутри прямоугольника задается текстовая область
            Text {
                id: taskDelegateText
                // здесь описана разметка текстовой области
                // данные берутся из модели списка taskIdModel
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
            // здесь описаны обработчики прямоугольной области
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    Qt.quit(0);
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

    // здесь для отображения используется список
    ListView {
        id: taskList
        // модель - это источник данных; поддерживается автоматическое обновление списка при изменении модели
        model: taskIdModel
        // делегат - это что-то вроде шаблона, по которому будет отображаться и обрабатываться список
        delegate: taskDelegate
        // прочие свойства списка
        anchors.fill: parent
        focus: true
    }
}


