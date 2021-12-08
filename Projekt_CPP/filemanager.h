#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <gameengine.h>
#include <vector>
#include <player.h>
#include <inventory.h>
#include <iostream>
#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>

class FileManager
{
private:
    std::string m_file;
public:
       FileManager();
       static std::vector<int>loadXml();

//    bool loadGame();
//    bool saveGame();

//    void write(QJsonObject &json) const;
//    void read(const QJsonObject);

//    void save();
//    void readFromFile(std::string file);

};

#endif // FILEMANAGER_H
