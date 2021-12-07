#include "seed.h"

Seed::Seed()
{

}
Seed::Seed(QString name, int cost){
    m_name = name;
    m_cost = cost;
};

void Seed::read(const QJsonObject &json){
    m_name = json["name"].toString();
    m_cost = json["cost"].toInt();
};

void Seed::write(QJsonObject &json)const{
    json["name"] = m_name;
    json["cost"] = m_cost;
};
