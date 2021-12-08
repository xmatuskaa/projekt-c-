#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <QObject>
#include <QFile>
#include <player.h>
#include <inventory.h>
#include <vector>
#include "filemanager.h"

class GameEngine : public QObject
{
        Q_OBJECT

    Q_PROPERTY(std::vector<int> getFields READ getFields NOTIFY fieldsChanged)
public:

   explicit GameEngine(QObject *parent = nullptr);

//    Q_INVOKABLE void drawDesk()

    Q_INVOKABLE void game();
    Q_INVOKABLE int  getPlayerPosition();
    Q_INVOKABLE  void movePlayer(QString where);
    Q_INVOKABLE QString getState(int index);
//    const Player* createPlayer() const;

    void newGame();
    bool loadGame(QString fileName);
    bool saveGame();
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;
    std::vector<int> getFields();

signals:
    void fieldsChanged();

public slots:
private:
    Player* m_player;

    std::vector<int> m_fields;
    QList<Seed> seeds;
    Inventory* inventory;

};

#endif // GAMEENGINE_H
