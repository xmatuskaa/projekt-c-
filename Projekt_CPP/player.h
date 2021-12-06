#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "inventory.h"

class Player
{
private:
    std::string m_name;
    Inventory* m_bag;
    int m_money;
public:
    Player();
};

#endif // PLAYER_H
