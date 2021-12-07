#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "inventory.h"
<<<<<<< Updated upstream
#include <QString>
=======
#include <QObject>
>>>>>>> Stashed changes

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
