import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Checkpoint Look-out")

    function pagePop() {
        mainView.pop()
    }

    StackView {
        id: mainView
        anchors.fill: parent
        initialItem: pageLogin
    }

    SimplePage {
        id: pageLogin
        header.visible: false

        onButtonBackClicked: {
            pagePop()
        }

        PageLogin {
            anchors.fill: parent

            onButtonConnectClicked: {
                mainView.push(pageSelectCheckpoint)
            }
            onButtonSettingsClicked: {
                mainView.push(pageSettings)
            }
        }
    }

    SimplePage {
        id: pageSettings
        header.visible: true
        headerText: "Настройки"
        visible: false

        onButtonBackClicked: {
            pagePop()
        }

        PageSettings {
            anchors.fill: parent

            onButtonSubmitClicked: {
                pagePop()
            }
        }
    }

    SimplePage {
        id: pageSelectCheckpoint
        header.visible: true
        headerText: "Выбор проходной"
        visible: false

        onButtonBackClicked: {
            pagePop()
        }

        PageSelectCheckpoint {
            anchors.fill: parent

            onButtonSelectClicked: {
                //pagePop()
            }
        }
    }


}
