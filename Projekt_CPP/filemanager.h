#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <gameengine.h>
#include <player.h>
#include <inventory.h>
#include <QFile>
#include <iostream>

class FileManager
{
private:
    std::string m_file;
public:
       FileManager();

//    bool loadGame();
//    bool saveGame();

//    void write(QJsonObject &json) const;
//    void read(const QJsonObject);

//    void save();
//    void readFromFile(std::string file);

};

#endif // FILEMANAGER_H
