#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QScreen>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    // example to query the device pixel ratio
    qDebug()<<"devicePixelRatio = "<<QGuiApplication::primaryScreen()->devicePixelRatio();

    return app.exec();
}
