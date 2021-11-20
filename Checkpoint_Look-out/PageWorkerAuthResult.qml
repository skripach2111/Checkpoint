import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Item {
    id: root

    signal buttonsClicked()

    property string stateText: "state"
    property string fio: "fio"
    property string position: "position"
    property string lvl_access: "lvl_access"
    property string dateAuth: "date"
    property string timeAuth: "time"

//    header: Button {
//        height: 50

//        anchors.left: parent.left
//        anchors.right: parent.right

//        text: stateText

//        onClicked: buttonsClicked()
//    }

//    footer: Button {
//        height: 50

//        anchors.left: parent.left
//        anchors.right: parent.right

//        text: stateText

//        onClicked: buttonsClicked()
//    }

    ColumnLayout {
        anchors.fill: parent

        Label {
            text: fio
        }

        Label {
            text: position
        }

        Label {
            text: lvl_access
        }

        Label {
            text: dateAuth
        }

        Label {
            text: timeAuth
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
