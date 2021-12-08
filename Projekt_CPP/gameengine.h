#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <QObject>
#include <QFile>
#include <player.h>
#include <inventory.h>

class GameEngine : public QObject
{
        Q_OBJECT
public:

   explicit GameEngine(QObject *parent = nullptr);

//    Q_INVOKABLE void drawDesk();
public:

    Q_INVOKABLE void game();
    Q_INVOKABLE int  getPlayerPosition();
    Q_INVOKABLE  void movePlayer(QString where);
//    const Player* createPlayer() const;

    void newGame();
    bool loadGame();
    bool saveGame();
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;


signals:
public slots:
private:
    Player* m_player;


};

#endif // GAMEENGINE_H
