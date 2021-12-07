#ifndef SEED_H
#define SEED_H
#include <QString>
#include "inventoryobject.h"

class Seed: InventoryObject
{
public:
    Seed();
    Seed(QString name, int cost);


private:
    int m_cost;
    QString m_name;
};

#endif // SEED_H
