import QtQuick 2.0

Rectangle {
    id: itemBar
    width: 380
    height: 80
    Grid{
        anchors.centerIn: parent
        id: itemGrid
        rows: 1
        Repeater{
            model: 6
            ItemSlot{
                slotIndex: index
                }
            }
    }
}
