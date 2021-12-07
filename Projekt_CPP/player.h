#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "inventory.h"
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>


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

    Inventory* createBag();

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;
};

#endif // PLAYER_H
