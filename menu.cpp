#include "menu.h"

Menu::Menu() {}

void Menu::Run()
{
    bool run = true;
    QTextStream out(stdout);
    QTextStream in(stdin);
    while(run)
    {
        out << "выберите права доступа:" << endl
            << "1 - банк" << endl
            << "2 - клиент" << endl
            << "3 - ВЫХОД" << endl;
        char command;
        in >> command;
        switch (command)
        {
        case '1':
        {
            SelectBankOperation();
            break;
        }
        case '2':
        {
            SelectClientOperation();
            break;
        }
        case '3':
        {
            run = false;
            break;
        }
        default:
            out << "неивестная команда";
            break;
        }
    }

}
