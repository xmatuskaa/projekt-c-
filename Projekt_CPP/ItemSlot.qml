import QtQuick 2.0

Rectangle {
    property int slotIndex: 0
    id: itemSlot
    width: 60
    height: 60
    radius: 5
    color: "lightgray"
    border.color: "gray"
    opacity: 50

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
                source: "Images/pumpkinseeds.png"
            }
        },
        State{
            name:"s_CarrotSeeds"

            PropertyChanges{
                target: itemSlotImage
                source: "Images/carrotseeds.png"
            }
        },
        State{
         name: "s_Pumpkin"
         PropertyChanges {
             target: itemSlotImage
             source: "Images/pumpkin.png"
         }

        },
        State{

        name:"s_Carrot"
        PropertyChanges {
            target: itemSlotImage
            source: "Images/carrot.png"
        }
        },
        State{
            name: "s_Sleep"
            PropertyChanges{
                target: itemSlotImage
                source: "Images/sleep.png"
            }
        }

    ]
    MouseArea{
        anchors.fill:parent
        hoverEnabled: true
        onClicked:{
            gameEngine.itemBarClicked(slotIndex);
        }
    }
}
