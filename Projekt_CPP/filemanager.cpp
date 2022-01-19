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

void FileManager::writeToIndex(int index, int number, QString filename){


    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)){
        QXmlStreamWriter writer;
        writer.setDevice(&file);
         writer.setAutoFormatting(true);
        writer.writeStartDocument();
        writer.writeStartElement("slot");


        for (int i = 0; i < 400; i++ ){
            if (index == i ){
                writer.writeStartElement("field");
                writer.writeAttribute("index",QString::number(i));
                writer.writeCharacters(QString::number(number));
            } else {

                writer.writeStartElement("field");
                writer.writeAttribute("index",QString::number(i));
                writer.writeCharacters("0");
                 writer.writeEndElement();
            }

        }


        writer.writeEndElement();
        writer.writeEndDocument();
    } else {
         qCritical() << "Soubor se nepovedlo otevritttt\n";
    }
file.close();
};

std::vector<int> FileManager::loadXml(){
    std::vector<int> slot(400, 0);

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
        qCritical() << "Soubor se nepovedlo otevritttt\n";
    }

    return slot;
}
