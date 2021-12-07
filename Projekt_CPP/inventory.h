#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>
#include "seed.h"
#include <QObject>

class Inventory
{
private:
    int m_capacity;
    std::vector <Seed*> m_inventory;

public:
    Inventory();
};

#endif // INVENTORY_H
