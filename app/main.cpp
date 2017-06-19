#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "preview.h"
#include <QQmlContext>
#include <QStringList>

int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.addImageProvider(QLatin1String("preview"), new QPdfPreview);
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    QPreviewData data;
    engine.rootContext()->setContextProperty("preview_data", &data);

    QStringList dataList;
    dataList.append("Item 1");
    dataList.append("Item 2");
    dataList.append("Item 3");
    dataList.append("Item 4");
    engine.rootContext()->setContextProperty("destinationModel", QVariant::fromValue(dataList));

    return app.exec();
}
