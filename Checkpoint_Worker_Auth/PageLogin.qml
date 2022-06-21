import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Item {
    id: root

    property alias errorText: label_error.text

    signal buttonConnectClicked(var login, var password)
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
            buttonConnectClicked(textFieldLogin.text, textFieldPassword.text)
        }
    }

//    Button {
//        id: buttonSettings
//        x: 532
//        width: 40
//        height: 40
//        text: qsTr("@")
//        anchors.right: parent.right
//        anchors.top: parent.top
//        display: AbstractButton.IconOnly
//        anchors.topMargin: 20
//        anchors.rightMargin: 20
//        font.pointSize: 12
//        icon: "qrc:/settings.png"

//        onClicked: {
//            buttonSettingsClicked()
//        }
//    }

    MouseArea {
        id: buttonSettings
        x: 532
        width: 40
        height: 40
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.rightMargin: 20
    Rectangle {
        color: "#494848"
        anchors.fill: parent

        Image {
            id: imageButtonSettings
            anchors.fill: parent
            source: "qrc:/settings.png"
            fillMode: Image.PreserveAspectFit
            //anchors.fill: parent
        }
    }

    onClicked: buttonSettingsClicked()
    }

    Label {
        id: label_error
        x: 304
        color: "#ff0000"
        text: qsTr("_error")
        anchors.top: rectangle.bottom
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 5
    }
}



/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
