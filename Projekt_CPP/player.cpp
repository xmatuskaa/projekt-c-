#include "player.h"

Player::Player()
{

}

void Player::read(const QJsonObject &json){
    if (json.contains("name") && json["name"].isString())
        m_name = json["name"].toString();
    if (json.contains("money") && json["money"].isDouble())
        m_money = json["money"].toInt();
};

void Player::write(QJsonObject &json) const{
    json["name"] = m_name;
    json["money"] = m_money;
};
