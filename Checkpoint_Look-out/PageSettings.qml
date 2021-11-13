import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Item {
    id: root

    signal buttonSubmitClicked()

    ColumnLayout {
        id: mainLayout
        x: 0
        y: 0
        width: 505
        height: 100

        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.margins: 10

        RowLayout {
            id: rowLayout
            width: 442
            height: 59

            Layout.fillWidth: true

            TextField {
                id: textFieldIP
                font.pointSize: 12
                placeholderText: qsTr("Адресс сервера")
            }

            Label {
                id: labelCurrentIP
                text: qsTr("Текущий: 127.0.0.1")
                font.italic: true
                font.bold: true
                font.pointSize: 12

                Layout.fillWidth: true
            }
        }

        RowLayout {
            id: rowLayout1
            width: 442
            height: 100

            Layout.fillWidth: true

            TextField {
                id: textFieldPort
                font.pointSize: 12
                placeholderText: qsTr("Порт")
            }

            Label {
                id: labelCurrentPort
                text: qsTr("Текущий: 3306")
                font.italic: true
                font.bold: true
                font.pointSize: 12

                Layout.fillWidth: true
            }
        }
    }

    Button {
        id: buttonApply
        x: 532
        width: 120
        height: 40
        text: qsTr("Применить")
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        anchors.rightMargin: 20
        font.pointSize: 12

        onClicked: {
            buttonSubmitClicked()
        }
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.75;height:480;width:640}
}
##^##*/
