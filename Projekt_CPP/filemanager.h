#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <iostream>

class FileManager
{
private:
    std::string m_file;
public:
    FileManager();
    void save();
    void readFromFile(std::string file);

};

#endif // FILEMANAGER_H