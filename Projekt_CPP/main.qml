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
}
