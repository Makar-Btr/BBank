#include <QCoreApplication>

#include "menu.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Menu menu;
    menu.Run();

    return a.exec();
}
