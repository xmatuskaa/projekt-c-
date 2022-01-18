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

    if (json.contains("player") && json["player"].isObject())
        m_player->read(json["player"].toObject());

    if (json.contains("inventory") && json["inventory"].isObject()){
        m_player->createBag(m_seeds)->read(json["inventory"].toObject());


//    m_player->read(json["player"].toObject());
//    m_player->createBag()->read(json["inventory"].toObject());

        }
};
void GameEngine::write(QJsonObject &json) const{
    QJsonObject playerObject;
       m_player->write(playerObject);
       json["player"] = playerObject;


       QJsonObject inventoryObject;
          m_inventory->write(inventoryObject);
          json["inventory"] = inventoryObject;

};

void GameEngine::movePlayer(QString where){
if(where=="up"){
   m_position-=20;
   emit playerPositionChanged();
}
if(where=="down"){
    m_position+=20;
    emit playerPositionChanged();
}
if(where=="left"){
    m_position-=1;
    emit playerPositionChanged();
}
if(where=="right"){
   m_position+=1;
   emit playerPositionChanged();
    //zmenit hodnotu v xmlku na 1
}
qCritical() << m_position <<"\n";
}

QString GameEngine::getPlayerPosition(int index){
    if (index == m_position){
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
  if(field.at(index)==1) return "s_Home";
  if(field.at(index)==2) return "s_FarmField";
  if(field.at(index)==3) return "s_Pumpkin";
  if(field.at(index)==4) return "s_Carrot";
    else return "s_Grass";
}

QString GameEngine::getBarState(int index){
   if (index == 0) return "s_Shovel";
   if (index == 1) return "s_PumpkinSeeds";
   if (index == 2) return "s_CarrotSeeds";
   if (index == 3) return "s_Pumpkin";
   if (index == 4) return "s_Carrot";
   if (index == 5) return "s_Sleep";
   else return "s_Sleep";
}

int GameEngine::getPositionNumber(){
    return m_position;
}

void GameEngine::setState(int index, int newValue){
    std::vector<int>  field = getFields();
    field.at(index)=newValue;
}

void GameEngine::itemSlotClicked(int index){
    if (index == 0){
        if (getState(index) != "s_Home"){
            setState(index, 2);
        }
    }
}
void GameEngine::itemBarClicked(int index){
    if(index==0){
       shovelClicked();
    }
    else if(index==1){
        plantPumpkins();
    }
    else if(index==2){
        plantCarrots();
    }
    else if(index==3){
    // pls insert selling pumpkins in the market
    }
    else if(index==4){
    //pls insert selling carrots at the market
    }
    else if(index==5){
        //go to sleep
        sleep();
    }
    else {
        std::cerr << "Error: did not log a slot index";
    }
}

void GameEngine::shovelClicked(){
    std::vector<int>  field = getFields();
    if (field.at(m_position)==1){
        //do nothing
    }
    else if (field.at(m_position)==2){
        //turn farmfield to grass
        setState(m_position, 0);
    }
    else if (field.at(m_position)==3){
        //harvest pumkin
        //-> add pumkin to inventory

        //-> change pumkinfield to farmfield
        setState(m_position, 2);
    }
    else if (field.at(m_position)==4){
        //harvest carrot
        //-> add carrot to inventory

        //-> change carrotfield to farmfield
        setState(m_position, 2);
    }
    else {
        //change grass to farmfield
        setState(m_position, 2);
    }
}

void GameEngine::plantPumpkins(){
    std::vector<int>  field = getFields();
    //is the field im standing on a farmfield?
    if (field.at(m_position)==2){
        //do i have pumpkin seeds available?
        if (m_pumpkinSeeds > 0){
            //remove 1 pumpkin seed from inventory
            m_pumpkinSeeds--;
            //notify inventory
            //notify screen
            //change from farmfield to stage one
            setState(m_position, 2);
        }
    }

}

void GameEngine::plantCarrots(){
    std::vector<int>  field = getFields();
    //is the field im standing on a farmfield?
    if (field.at(m_position)==2){
        //do i have carrot seeds available?
        if (m_carrotSeeds > 0){
            //remove 1 carrot seed from inventory
            m_carrotSeeds--;
            //notify inventory
            //notify screen
            //change from farmfield to stage one
            setState(m_position, 2);
        }
    }
}
void GameEngine::sleep(){
    //save game to files
    //change day to +1
    //grow seeds
}

