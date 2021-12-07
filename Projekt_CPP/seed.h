#ifndef SEED_H
#define SEED_H
#include <QString>
#include <QJsonObject>
#include "inventoryobject.h"

class Seed: InventoryObject
{
public:
    Seed();
    Seed(QString name, int cost);

    void read(const QJsonObject &json);
    void write(QJsonObject &json)const;

private:
    int m_cost;
    QString m_name;
};

#endif // SEED_H
