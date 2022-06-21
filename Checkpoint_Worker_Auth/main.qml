import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import com.custom 1.0


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Checkpoint Look-out")

    function pagePop() {
        mainView.pop()
    }

    ConnectionController {
        id: connectionController

        onErrorConnection: {
            pageLoginContents.errorText = message;
            errorLabel.text = message;
            pageError.visible = true;
        }

        onConnected: {
            getCheckpointModel();
            pageLoginContents.errorText = ""
        }

        onComingCheckpointModel: {
            pageSelectCheckpointContent.comboBoxModel = connectionController.checkpoint
            mainView.push(pageSelectCheckpoint)
        }

        onComingStateModel: {
            statesComboBox.model = connectionController.state
            mainView.push(pageQrReader)
        }

        onWorkerAuthoriazationResult: {
            pageAuthResultContent.fio = fio
            pageAuthResultContent.position = position
            pageAuthResultContent.lvl_access = lvl_access
            pageAuthResultContent.dateAuth = date
            pageAuthResultContent.timeAuth = time
            pageAuthResultContent.stateText = state
            if(color)
                pageAuthResultContent.colorButtons = "green"
            else
                pageAuthResultContent.colorButtons = "red"

            mainView.push(pageAuthResultContent)
        }
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
            id: pageLoginContents
            anchors.fill: parent
            errorText: ""

            onButtonConnectClicked: {

                if(login.length != 0 && password.length != 0)
                {
                    connectionController.login = login
                    connectionController.password = password
                    connectionController.connect()
                }
                else
                    errorText = "Все поля должны быть заполнены!"
            }
            onButtonSettingsClicked: {
                pageSettingsContent.currentIP = connectionController.getSettings("Connection/ip_address")
                pageSettingsContent.currentPort = connectionController.getSettings("Connection/port")

                if(pageSettingsContent.currentIP.length == 0)
                    pageSettingsContent.currentIP = "127.0.0.1"

                if(pageSettingsContent.currentPort == "0")
                    pageSettingsContent.currentPort = "12012"
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
            pageSettingsContent.fieldIP = ""
            pageSettingsContent.fieldPort = ""

            pagePop()
        }

        PageSettings {
            id: pageSettingsContent
            anchors.fill: parent

            onButtonSubmitClicked: {

                if(fieldIP.length != 0)
                    connectionController.setSettings("Connection/ip_address", fieldIP)
                if(fieldPort.length != 0)
                    connectionController.setSettings("Connection/port", fieldPort)

                currentIP = connectionController.getSettings("Connection/ip_address")
                currentPort = connectionController.getSettings("Connection/port")

                pageSettingsContent.fieldIP = ""
                pageSettingsContent.fieldPort = ""
            }
        }
    }

    SimplePage {
        id: pageSelectCheckpoint
        header.visible: true
        headerText: "Выбор проходной"
        visible: false

        onButtonBackClicked: {
            connectionController.disconnect()
            pagePop()
        }

        PageSelectCheckpoint {
            id: pageSelectCheckpointContent
            anchors.fill: parent

            onButtonSelectClicked: {
                pageQrReaderContent.scanActive = true
                connectionController.getStatesModel()
                //pagePop()
            }
        }
    }

    SimplePage {
        id: pageQrReader
        header.visible: true
        headerText: "Сканер"
        visible: false

        PageQrReader {
            id: pageQrReaderContent
            anchors.fill: parent
            scanActive: false

            onCodeReaded: {
                pageQrReaderContent.scanActive = false
                connectionController.authWorker(pageSelectCheckpointContent.selectCheckpoint, code, statesComboBox.currentIndex)
                console.log("onCodeReaded")
            }
        }

        footer: ComboBox {
            id: statesComboBox
            height: 50
            anchors.left: parent.left
            anchors.right: parent.right

            textRole: "title"
            valueRole: "value"
        }

        onButtonBackClicked: {
            connectionController.disconnect()
            mainView.pop(pageLogin)
        }
    }


    PageWorkerAuthResult {
        id: pageAuthResultContent

        anchors.fill: parent
        visible: false

        onButtonsClicked: {
            pagePop()
            pageQrReaderContent.scanActive = true
        }
    }

}
