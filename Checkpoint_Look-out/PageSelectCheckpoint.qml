import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Item {
    id: root

    signal buttonSelectClicked()

    property alias comboBoxModel: comboBox_selectCheckpoint.model
    property alias selectCheckpoint: comboBox_selectCheckpoint.currentIndex

    ColumnLayout {
        id: column
        x: 84
        y: 90
        width: 236
        height: 78
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 5

        Label {
            id: label
            text: qsTr("Выберите Вашу проходную:")
            font.pointSize: 12

            Layout.fillWidth: true
        }

        ComboBox {
            id: comboBox_selectCheckpoint

            Layout.fillWidth: true

            textRole: "title"
            valueRole: "value"
        }

    }

    Button {
        id: buttonSelectCheckpoint
        x: 318
        y: 219
        width: 120
        height: 40
        text: qsTr("Выбрать")
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        font.pointSize: 12
        anchors.bottomMargin: 20
        anchors.rightMargin: 20

        onClicked: {
            buttonSelectClicked()
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.75;height:480;width:640}
}
##^##*/
