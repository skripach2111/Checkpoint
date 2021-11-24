import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtMultimedia 5.12
import com.scythestudio.scodes 1.0

Item {
    id: root

    property bool scanActive: false

    signal codeReaded(var code)

    Camera {
        id: camera
        focus {
            focusMode: CameraFocus.FocusContinuous
            focusPointMode: CameraFocus.FocusPointAuto
        }
    }

    VideoOutput {
        id: videoOutput
        anchors.fill: parent
        source: camera
        anchors.topMargin: 0
        autoOrientation: true
        fillMode: VideoOutput.PreserveAspectCrop
        // add barcodeFilter to videoOutput's filters to enable catching barcodes
        filters: [barcodeFilter]

        onSourceRectChanged: {
            barcodeFilter.captureRect = videoOutput.mapRectToSource(
                        videoOutput.mapNormalizedRectToItem(Qt.rect(0.25, 0.25, 0.5, 0.5)))
        }

        //        ScannerOverlay {
        //            id: scannerOverlay
        //            anchors.fill: parent

        //            captureRect: videoOutput.mapRectToItem(barcodeFilter.captureRect)
        //        }

        // used to get camera focus on touched point
        MouseArea {
            onClicked: {

                //                camera.focus.customFocusPoint = Qt.point(mouse.x / width,
                //                                                         mouse.y / height)
                camera.focus.customFocusPoint = Qt.point(width/2, height/2)
                camera.focus.focusMode = CameraFocus.FocusMacro
                camera.focus.focusPointMode = CameraFocus.FocusPointCustom
            }
        }
    }

    SBarcodeFilter {
        id: barcodeFilter
        active: scanActive

        // you can adjust capture rect (scan area) ne changing these Qt.rect() parameters
        captureRect: videoOutput.mapRectToSource(
                         videoOutput.mapNormalizedRectToItem(Qt.rect(0.25, 0.25,
                                                                     0.5, 0.5)))

        onCapturedChanged: {
            codeReaded(captured)
            console.log("captured: " + captured)
            log.text = "captured: " + captured
        }
    }

    Label {
        id: log
        height: 50

        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        text: "log"
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.9}
}
##^##*/
