import QtQuick 2.0

Rectangle {
width: 180
height: 60
radius: 5
color: "darkorange"
Text {
    property int day: 0
    id: dayCounter
    text:"Day: " + String(day)
    anchors.bottom: parent.bottom
    font {
        pixelSize: 20
        bold: true
         }
    }
Text {
    property int money: 0
    id: moneyCounter
    text:"Money: " + String(money)
    anchors.right: parent.right
    anchors.bottom: parent.bottom
    font {
        pixelSize: 20
        bold: true
         }
}
}
