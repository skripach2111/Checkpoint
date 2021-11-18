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
            mainView.push(pageSelectCheckpoint)
        }
    }

    ModelForComboBox {
        id: checkpointModel
        source: connectionController.checkpoint
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
            db.disconnect()
            pagePop()
        }

        PageSelectCheckpoint {
            id: pageSelectCheckpointContent
            anchors.fill: parent

            onButtonSelectClicked: {
                //pagePop()
            }
        }
    }


}
