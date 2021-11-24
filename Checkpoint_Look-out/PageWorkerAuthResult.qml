import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Page {
    id: root

    signal buttonsClicked()

    property string stateText: "state"
    property string fio: "fio"
    property string position: "position"
    property string lvl_access: "lvl_access"
    property string dateAuth: "date"
    property string timeAuth: "time"
    property string colorButtons: "red"

    header: Button {
        height: 50

        anchors.left: parent.left
        anchors.right: parent.right
        font.bold: true
        font.pointSize: 14

        text: stateText

        background: Rectangle {
            color: colorButtons
        }

        onClicked: buttonsClicked()
    }

    footer: Button {
        height: 50

        anchors.left: parent.left
        anchors.right: parent.right
        font.bold: true
        font.pointSize: 14

        text: stateText

        background: Rectangle {
            color: colorButtons
        }

        onClicked: buttonsClicked()
    }

    ColumnLayout {
        anchors.fill: parent

        Label {
            text: "ФИО:"
            font.underline: true
            font.bold: true
            font.italic: false
            font.pointSize: 10
        }

        Label {
            text: fio
        }

        Label {
            text: "Должность:"
            font.underline: true
            font.bold: true
            font.italic: false
            font.pointSize: 10
        }

        Label {
            text: position
        }

        Label {
            text: "Уровень доступа:"
            font.underline: true
            font.bold: true
            font.italic: false
            font.pointSize: 10
        }

        Label {
            text: lvl_access
        }

        Label {
            text: "Дата авторизации:"
            font.underline: true
            font.bold: true
            font.italic: false
            font.pointSize: 10
        }

        Label {
            text: dateAuth
        }

        Label {
            text: "Время авторизации:"
            font.underline: true
            font.bold: true
            font.italic: false
            font.pointSize: 10
        }

        Label {
            text: timeAuth
        }

        Item {
            Layout.fillHeight: true
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
