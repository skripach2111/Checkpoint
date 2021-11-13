import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Item {
    id: root

    signal buttonConnectClicked()
    signal buttonSettingsClicked()

    Rectangle {
        id: rectangle
        y: 140
        height: 177
        color: "#ffffff"
        radius: 10
        border.width: 1
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.leftMargin: 10

        ColumnLayout {
            id: column

            anchors.fill: parent
            anchors.margins: 15
            clip: true
            spacing: 10

            Label {
                id: label
                text: qsTr("Авторизация")
                verticalAlignment: Text.AlignVCenter
                font.bold: true
                font.pointSize: 24

                Layout.fillWidth: true;
            }

            TextField {
                id: textFieldLogin
                font.italic: true
                font.pointSize: 12
                placeholderText: qsTr("Логин")

                Layout.fillWidth: true;
            }

            TextField {
                id: textFieldPassword
                text: ""
                font.italic: true
                font.pointSize: 12
                placeholderText: qsTr("Пароль")

                echoMode: TextInput.Password


                Layout.fillWidth: true;
            }
        }
    }

    Button {
        id: buttonLogin
        x: 532
        y: 432
        width: 120
        height: 40
        text: qsTr("Вход")
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        font.pointSize: 12
        anchors.bottomMargin: 20
        anchors.rightMargin: 20

        onClicked: {
            buttonConnectClicked()
        }
    }

    Button {
        id: buttonSettings
        x: 532
        width: 40
        height: 40
        text: qsTr("@")
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.rightMargin: 20
        font.pointSize: 12

        onClicked: {
            buttonSettingsClicked()
        }
    }
}



/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.66;height:480;width:640}
}
##^##*/
