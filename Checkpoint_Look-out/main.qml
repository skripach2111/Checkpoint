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

    //    DatabaseModule {
    //        id: db

    //        hostAddress: "213.110.121.129"
    //        hostPort: 3306
    //    }

    ConnectionController {
        id: connectionController

        onErrorConnection: {
            pageLoginContents.errorText = message;
        }

        onConnected: {
            getCheckpointModel();
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
            pageQrReaderContent.scanActive = false
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
                //                if(db.connect("userCheckpoint", "user_checkpoint"))
                //                {
                //                    if(db.authorizationUser(login, password))
                //                    {
                //                        mainView.push(pageSelectCheckpoint)
                //                    }
                //                    else
                //                        pageLoginContents.errorText = "Неверный логин или пароль!"
                //                }
                //                else
                //                {
                //                    pageLoginContents.errorText = "Не удалось подключиться к серверу!"
                //                }

                connectionController.login = login
                connectionController.password = password
                connectionController.connect()
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

            onCodeReaded: connectionController.authWorker(pageSelectCheckpointContent.selectCheckpoint, code, statesComboBox.currentIndex)
        }

        footer: ComboBox {
            id: statesComboBox
            height: 50
            anchors.left: parent.left
            anchors.right: parent.right

            textRole: "title"
            valueRole: "value"
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
