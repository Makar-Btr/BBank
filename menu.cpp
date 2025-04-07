#include "menu.h"

Menu::Menu() : in(stdin), out(stdout) {}

void Menu::Run()
{
    bool run = true;
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
        case '^':
        {
            out << "Уходи, тебя сюда не приглашали!";
            break;
        }
        default:
        {
            out << "неивестная команда";
            break;
        }
        }
    }
}

void Menu::SelectBankOperation()
{
    bool run = true;
    while(run)
    {
        out << "выберите команду" << endl
            << "1 - посмотреть все банки" << endl
            << "2 - создать новый банк" << endl
            << "3 - выбрать банк" << endl
            << "4 - ВЫХОД" << endl;
        char command;
        in >> command;
        switch (command)
        {
        case '1':
        {
            GetAllBanks();
            break;
        }
        case '2':
        {
            AddNewBank();
            break;
        }
        case '3':
        {
            ChooseBank();
            break;
        }
        case '4':
        {
            run = false;
            break;
        }
        default:
        {
            out << "неивестная команда";
            break;
        }
        }
    }
}





void Menu::SelectClientOperation()
{
    bool run = true;
    while(run)
    {
        out << "выберите команду" << endl
            << "1 - посмотреть все клиенты" << endl
            << "2 - создать нового клиента" << endl
            << "3 - выбрать клиента" << endl
            << "4 - ВЫХОД" << endl;
        char command;
        in >> command;
        switch (command)
        {
        case '1':
        {
            GetAllClients();
            break;
        }
        case '2':
        {
            AddNewClient();
            break;
        }
        case '3':
        {
            ChooseClient();
            break;
        }
        case '4':
        {
            run = false;
            break;
        }
        default:
        {
            out << "неивестная команда";
            break;
        }
        }
    }
}







void Menu::GetAllBanks()
{

}

void Menu::AddNewBank()
{

}

void Menu::ChooseBank()
{

}

void Menu::GetAllClients()
{

}

void Menu::AddNewClient()
{

}

void Menu::ChooseClient()
{

}


