#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <QObject>
#include <QFile>
#include <player.h>
#include <inventory.h>

class GameEngine : public QObject
{
        Q_OBJECT

    Q_PROPERTY(QVariant fields READ getFields NOTIFY fieldsChanged)
public:

   explicit GameEngine(QObject *parent = nullptr);

//    Q_INVOKABLE void drawDesk()

    Q_INVOKABLE void game();
    Q_INVOKABLE int  getPlayerPosition();
    Q_INVOKABLE  void movePlayer(QString where);
//    const Player* createPlayer() const;

    void newGame();
    bool loadGame(QString fileName);
    bool saveGame();
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;
    QVariant getFields();

signals:
    void fieldsChanged();

public slots:
private:
    Player* m_player;

    QVariant* fields;
    QList<Seed> seeds;
    Inventory* inventory;

};

#endif // GAMEENGINE_H
