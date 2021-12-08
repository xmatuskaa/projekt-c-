#include "gameengine.h"

GameEngine::GameEngine(QObject *parent) : QObject(parent)
{
m_player = new Player;
m_fields = FileManager::loadXml();
}

//void GameEngine::drawDesk(){

//}

//const Player* GameEngine::createPlayer() const{
//    Player* m_player = new Player();
//    m_player->createBag();
//    return m_player;
//};

void GameEngine::game(){
m_player = new Player;
}



void GameEngine::newGame(){


};
bool GameEngine::loadGame(QString fileName){
    QFile loadFile(fileName);
    if (!loadFile.open(QIODevice::ReadOnly)){
        qWarning("Couldnt open save file");
        return false;
    }
    QByteArray saveDate = loadFile.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveDate));

    read(loadDoc.object());
    return true;
};
bool GameEngine::saveGame(){
    QFile saveFile("save.json");
    if (!saveFile.open(QIODevice::WriteOnly)){
        qWarning("Couldnt open save file");
        return false;
    }

    QJsonObject gameObject;
    write(gameObject);
    QJsonDocument saveDoc(gameObject);
    saveFile.write(saveDoc.toJson());

    return true;
};
void GameEngine::read(const QJsonObject &json){
    m_player->read(json["player"].toObject());
    m_player->createBag()->read(json["inventory"].toObject());

};
void GameEngine::write(QJsonObject &json) const{
    QJsonObject playerObject;
       m_player->write(playerObject);
       json["player"] = playerObject;


};

void GameEngine::movePlayer(QString where){
if(where=="up"){

    m_player->setPosition(m_player->getPosition()-20);
}
if(where=="down"){

    m_player->setPosition(m_player->getPosition()+20);
}
if(where=="left"){

    m_player->setPosition(m_player->getPosition()-1);
}
if(where=="right"){

    m_player->setPosition(m_player->getPosition()+1);
    //zmenit hodnotu v xmlku na 1
    emit fieldsChanged();
}
}
QString GameEngine::getPlayerPosition(int index){
    if (index == m_player->getPosition()){
        return "s_Player";
    }
    else {
        return "s_Empty";
    }
}

std::vector<int> GameEngine::getFields(){
m_fields = FileManager::loadXml();
return m_fields;
}

QString GameEngine::getState(int index){
  std::vector<int>  field = getFields();
    if(field.at(index)==1) return "s_Player";
    if(field.at(index)==2) return "s_FarmField";
    else return "s_Grass";
}
