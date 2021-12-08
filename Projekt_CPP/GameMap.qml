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
            state:/*if(gameEngine.getPositionNumber===index){
                     return "s_Player";
                      }
                      else {
                          return "s_Empty";
                      }*/gameEngine.getPlayerPosition(index);

                    }
                 }
            }
        }

