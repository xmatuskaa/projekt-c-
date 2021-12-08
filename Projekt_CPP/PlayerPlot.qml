import QtQuick 2.0

Rectangle {
    property int plotIndex: 0
    id: playerPlot
    width: 40
    height: 40

    Image {
    id: playerImage
    source: ":/Images/player2.png"
    width: parent.width
    height: parent.height
    anchors.centerIn: parent
    }

    states:[
        State{
            name: "s_Empty"
            PropertyChanges {
               target: playerImage
                opacity: 0
                 }

    },
        State{
                name: "s_Player"
                PropertyChanges {
                    target: playerImage
                    opacity: 100
                     }
            }
    ]
}
