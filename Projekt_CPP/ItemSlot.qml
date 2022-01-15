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

        },
        State{
            name: "s_PumpkinSeeds"
            PropertyChanges{
                target: itemSlotImage
                source: "Images/pumpkinfield.png"
            }
        },
        State{
            name:"s_CarrotSeeds"
            PropertyChanges{
                target: itemSlotImage
                source: "Images/carrotfield.png"
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
