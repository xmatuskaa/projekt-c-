#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "inventory.h"
#include <QString>

class Player
{
private:
    QString m_name;
    Inventory* m_bag;
    int m_money;
    //int level;

public:
    Player();
    Player(QString name,int money);


};

#endif // PLAYER_H
