import QtQuick 2.0

Rectangle {
    property string previousState: ""
    property int plotIndex: 0
    id: farmPlot
    color: black
    width: 40
    height: 40

    Image {
    id: plotImage
    source: ""
    width: parent.width
    height: parent.height
    anchors.centerIn: parent
    }

    //border.color: "black"
    Text {
        id: zkouskaFunkcichIndexu
        text: plotIndex
       anchors.centerIn: parent
    }
    states: [
    State{
        name: "s_Grass"
        PropertyChanges {
            target: farmPlot
            color: "green"
             }
        },
    State{
        name: "s_FarmField"
        PropertyChanges {
            target: farmPlot
            color: "brown"
             }
        },
        State{
        name: "s_Player"
        PropertyChanges {
            target: plotImage
            source: "images/player2.png"
             }

        }
    ]
    Keys.onRightPressed: {
        gameEngine.movePlayer("right");
        if(plotIndex===gameEngine.getPlayerPosition) farmPlot.state = "s_FarmField";
    }
}
