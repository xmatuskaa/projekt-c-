import QtQuick 2.0

Rectangle {
    id: gameMap
    color:"grey"
    width: 20*40
    height: width

    Grid{
        id: gameGrid
        rows: 20
        Repeater{
        model: 20*20

        PlayerPlot{
            plotIndex: index

        }

        FarmPlot{
            plotIndex: index
            state: gameEngine.getState(index);
            
                     }
        }
    }
}
