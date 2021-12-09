import QtQuick 2.0

Rectangle {
    property int slotIndex: 0
    id: itemSlot
    width: 60
    height: 60
    radius: 5
    color: "lightgray"
    border.color: "gray"

    Image {
            id: itemSlotImage
            source: ""
            width: parent.width
            height: parent.height
            anchors.centerIn: parent
            }
    states:[
        State{
            name: "s_Shovel"
            PropertyChanges {
                target: itemSlotImage
                source: "Images/shovel.png"
            }

        }

    ]
    MouseArea{
        anchors.fill:parent
        hoverEnabled: true
        onClicked:{

        }
    }
}
