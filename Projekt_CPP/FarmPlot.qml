import QtQuick 2.0

Rectangle {
    property string previousState: ""
    property int plotIndex: 0
    id: farmPlot
    color: "black"
    opacity: 50
    width: 37
    height: 37
    Image {
            id: plotImage
            source: ""
            width: parent.width
            height: parent.height
            anchors.centerIn: parent
            }




    //border.color: "black"
    /*Text {
        id: zkouskaFunkcichIndexu     
        text:plotIndex
       anchors.centerIn: parent
    }*/
    states: [
    State{
        name: "s_Grass"
        PropertyChanges {
            target: plotImage
            source: "Images/grass2.png"
             }
        },
    State{
        name: "s_FarmField"
        PropertyChanges {
            target: plotImage
            source: "Images/fieldongrass2.png"
             }
        },
        /*State{
            name: "s_Home"
            PropertyChanges {
                target: plotImage
                source: "Images/house.png"
                 }
            },*/
        State {
            name:"s_Mansion1"
            PropertyChanges{
                target:plotImage
                source: "Images/mansion21.png"
            }
        },
        State {
            name:"s_Mansion2"
            PropertyChanges{
                target:plotImage
                source: "Images/mansion22.png"
            }
        },
        State {
            name:"s_Mansion3"
            PropertyChanges{
                target:plotImage
                source: "Images/mansion23.png"
            }
        },
        State {
            name:"s_Mansion4"
            PropertyChanges{
                target:plotImage
                source: "Images/mansion24.png"
            }
        },
        State{
            name: "s_Pumpkin"
            PropertyChanges {
                target: plotImage
                source: "Images/fieldpumpkin2.png"
                 }
            },
        State{
            name: "s_Carrot"
            PropertyChanges {
                target: plotImage
                source: "Images/carrotfield2.png"
                 }
            },
        State{
            name: "s_PumpkinStageOne"
            PropertyChanges {
                target: plotImage
                source: "Images/stageone2.png"
                 }
            },
        State{
            name: "s_PumpkinStageTwo"
            PropertyChanges {
                target: plotImage
                source: "Images/stagetwo2.png"
                 }
            },
        State{
            name: "s_CarrotStageOne"
            PropertyChanges {
                target: plotImage
                source: "Images/stageone2.png"
                 }
            },
        State{
            name: "s_CarrotStageTwo"
            PropertyChanges {
                target: plotImage
                source: "Images/stagetwo2.png"
                 }
            },
        State{
            name: "s_MarketSell"
            PropertyChanges {
                target: plotImage
                source: "Images/market1.png"
                 }
            },
        State{
            name: "s_MarketBuy"
            PropertyChanges {
                target: plotImage
               source: "Images/market2.png"
                 }
            }
        /*State{
        name: "s_Player"
        PropertyChanges {
            target: plotImage
            source: "images/player2.png"
             }

        }*/
    ]

}
