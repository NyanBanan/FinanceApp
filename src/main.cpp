//
// Created by nyanbanan on 10.02.24.
//

#include <QApplication>
#include <QQmlApplicationEngine>

int main(int argc, char* argv[]){
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/FinanceAppQml/main.qml")));

    return app.exec();
}