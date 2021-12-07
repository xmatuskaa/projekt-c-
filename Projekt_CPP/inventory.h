#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include "seed.h"


class Inventory
{
private:
    int m_capacity;
    std::vector <Seed*> m_inventory;

public:
    Inventory();

    void setSeed(std::vector<Seed*> seedVector);
    void read(const QJsonObject &json);
    void write(QJsonObject &json);
};

#endif // INVENTORY_H
