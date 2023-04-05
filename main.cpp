#include "mainscene.h"
#include <QApplication>
#include <QResource>
#include "config.h"
#include <QIcon>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QResource::registerResource(GAME_RES_PATH);
    MainScene begin;

    MainScene w;
    w.show();
    return a.exec();
}
