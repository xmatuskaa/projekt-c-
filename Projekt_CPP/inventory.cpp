#include "inventory.h"

Inventory::Inventory()
{

}

void Inventory::setSeed(std::vector<Seed*> seedVector){

};
void Inventory::read(const QJsonObject &json){

    if (json.contains("seeds") && json["seeds"].isArray()){
        QJsonArray seedArray = json["seeds"].toArray();
        m_seeds.clear();
        m_seeds.reserve(seedArray.size());
        for (int seedIndex = 0; seedIndex < seedArray.size(); ++seedIndex){
            QJsonObject seedObject = seedArray[seedIndex].toObject();
            Seed seed;
            seed.setName(seedObject["name"].toString());
            seed.setCost(seedObject["cost"].toInt());
            m_seeds.push_back(&seed);
        }
    }



};
void Inventory::write(QJsonObject &json){
    QJsonArray seedArray;
    foreach (Seed* seed, m_seeds){
        QJsonObject seedObject;
        seedObject["name"] = seed->getName();
        seedObject["cost"] = seed->getCost();
        seedArray.append(seedObject);
     }
    json["seeds"] = seedArray;

};
