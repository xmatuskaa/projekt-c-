import QtQuick 2.0

Rectangle {
    id: gameMap
    color:"grey"
    width: 20*40
    height: width
    property int position: gameEngine.getPositionNumber
    //property QString state: gameEngine.getState


    Grid{
        id: gameGrid
        rows: 20
        Repeater{
        model: 20*20
        FarmPlot{
            plotIndex: index
            state: gameEngine.getState(index);
                     }
        }
    }
    Grid{
        id: playerGrid
        rows: 20
        Repeater{
        model: 20*20
        PlayerPlot{
            plotIndex: index
            state:if(plotIndex==position){
                  return "s_Player"}
            else return "s_Empty"

                    }
                 }
            }
        }

