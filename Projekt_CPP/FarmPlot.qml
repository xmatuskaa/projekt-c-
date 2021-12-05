import QtQuick 2.0

Rectangle {
    property int plotIndex: 0
    id: farmPlot
    color: black
    width: 40
    height: 40
    //border.color: "black"
    /*Text {
        id: zkouskaFunkcichIndexu
        text: plotIndex
       anchors.centerIn: parent
    }*/
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

        }


    ]
}
