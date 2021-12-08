#include "filemanager.h"

FileManager::FileManager()
{

}
//bool FileManager::loadGame(){

//};
//bool FileManager::saveGame(){
//    QFile loadFile("save.json");
//    if (!loadFile.open(QIODevice::ReadOnly)){
//        qWarning("Couldnt open save file");
//        return false;
//    }
//    QJsonObject gameObject;
//    write(gameObject);
//};

//void FileManager::write(QJsonObject &json) const{

//};
//void FileManager::read(const QJsonObject){

//};

std::vector<int> FileManager::loadXml(){
    std::vector<int> slot(36, 0);

    QFile file(":/save.xml");
    if (file.open(QIODevice::ReadOnly)){

        QXmlStreamReader xmlReader;
        xmlReader.setDevice(&file);
        xmlReader.readNext();

        while(!xmlReader.isEndDocument()){

            if (xmlReader.isStartElement()){
                QString name = xmlReader.name().toString();
                if (name=="field"){

                    int index = xmlReader.attributes().value("index").toInt();
                    int slotContent = xmlReader.readElementText().toInt();
                    slot.at(index) = slotContent;
                } else if (name == "slot"){
                    // skip
                } else {
                    qCritical() << "Narazil jsem na element jiny nez field" << name <<"\n";
                }
            }
            // nactu dalsi element
            xmlReader.readNext();
        }
    } else {
        qCritical() << "Soubor se nepovedlo otevrit\n";
    }

    return slot;
}
