#include "inventory.h"

Inventory::Inventory()
{

}

void Inventory::setSeed(std::vector<Seed*> seedVector){

};
void Inventory::read(const QJsonObject &json){
    m_inventory.clear();
    QJsonArray seedArray = json["seeds"].toArray();
    for (int index = 0; index < seedArray.size(); ++index){
        QJsonObject seedObject = seedArray[index].toObject();
        Seed seed;
        seed.read(seedObject);
        m_inventory.push_back(&seed);
    }
};
void Inventory::write(QJsonObject &json){
    QJsonArray seedArray;
    foreach (const Seed* seed, m_inventory){
        QJsonObject seedObject;
        seed->write(seedObject);
        seedArray.append(seedObject);
    }
    json["seeds"] = seedArray;
};
