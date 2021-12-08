import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 1920
    height: 1080
    visible: true
    title: qsTr("Farm")

    GameMap{
        id:gameMap
        anchors.centerIn: parent
    }
    ItemBar{
        anchors{
            bottom: gameMap.top
            right: gameMap.right
        }
    }
    StatusBar{
        anchors{
            bottom: gameMap.top
            left: gameMap.left
        }
    }

    Item {
        anchors.fill: parent
        focus: true
        Keys.onPressed: function (event) {
            console.log("ahooojj");
            if (event.key === Qt.Key_Right) {
                gameEngine.movePlayer("right");
                var position= gameEngine.getPlayerPosition
                if(plotIndex==position) farmPlot.state = "s_FarmField";
            }
        }
    }


}
