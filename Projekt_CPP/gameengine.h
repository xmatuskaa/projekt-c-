#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <QObject>




class GameEngine : public QObject
{
        Q_OBJECT
public:
   explicit GameEngine(QObject *parent = nullptr);

    Q_INVOKABLE void drawDesk();
public:
    Q_INVOKABLE void game();
signals:

};

#endif // GAMEENGINE_H
