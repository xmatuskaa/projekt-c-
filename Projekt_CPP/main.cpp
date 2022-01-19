#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "gameengine.h"
#include "filemanager.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

        GameEngine gameEngine;
 QQmlContext* context = engine.rootContext();
context->setContextProperty("gameEngine", &gameEngine);
    engine.load(url);

//   FileManager* fm = new FileManager();
//   std::cout << fm->getValueFronXML(17);
////   for (int i = 0; i < 10; i++){
////       fm->writeToIndex(i,2, "/Users/evgeniavolkova/3 semestr/git_cpc/projekt-c-/Projekt_CPP/forSaving.xml");
////   }


    return app.exec();
}
