#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <QObject>
#include <QFile>
#include <iostream>
#include <player.h>
#include <inventory.h>
#include <vector>
#include "filemanager.h"

class GameEngine : public QObject
{
        Q_OBJECT

    Q_PROPERTY(int getPositionNumber READ getPositionNumber  NOTIFY playerPositionChanged)
    //Q_PROPERTY(QString getState(index) READ getState(index) NOTIFY stateChanged)
public:

   explicit GameEngine(QObject *parent = nullptr);

//    Q_INVOKABLE void drawDesk()

    Q_INVOKABLE void game();
    //Q_INVOKABLE QString  getPlayerPosition(int index);
    Q_INVOKABLE  void movePlayer(QString where);
    Q_INVOKABLE QString getState(int index);
    Q_INVOKABLE QString getBarState(int index);
    Q_INVOKABLE void itemSlotClicked(int index);

//    const Player* createPlayer() const;

    void newGame();
    bool loadGame(QString fileName);
    bool saveGame();
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;
    std::vector<int> getFields();
    int getPositionNumber();
    void setState(int index, int newValue);


signals:
    void fieldsChanged();
    void playerPositionChanged();

public slots:
    QString  getPlayerPosition(int index);
private:
    Player* m_player;

    std::vector<int> m_fields;

    std::vector<Seed*> m_seeds;
    //QList<Seed> m_seeds;
    Inventory* m_inventory;
int m_position = 30;

};

#endif // GAMEENGINE_H
