import QtQuick 2.0
import QtQuick.Controls 2.15

Rectangle {
    id: gameMap
    color:"grey"
    width: 20*37
    height: width
    property int position: gameEngine.getPositionNumber




    Grid{
        id: gameGrid
        rows: 20
        Repeater{
        model: 20*20
        //property int type: gameEngine.getFieldsAt(plotIndex)
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
