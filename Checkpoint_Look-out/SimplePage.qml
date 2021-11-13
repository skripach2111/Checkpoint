import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Page {
    id: root

    property alias buttonBack: buttonBack.visible
    property alias headerText: title.text

    signal buttonBackClicked()
    signal buttonNextClicked()

    header: ToolBar {
        height:  50

        RowLayout {
        anchors.fill: parent
        spacing: 5

            ToolButton {
                id: buttonBack
                text: "<"
                anchors.verticalCenter: parent.verticalCenter
                onClicked: {
                    buttonBackClicked()
                }
            }

            Label {
                id: title
                text: "Title"
                font.bold: true
                font.pointSize: 16

                Layout.fillWidth: true
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
