#include "menu.h"

Menu::Menu() : in(stdin), out(stdout) {}

void Menu::Run()
{
    bool run = true;
    while(run)
    {
        out << "выберите права доступа:" << endl
            << "\t1 - банк" << endl
            << "\t2 - клиент" << endl
            << "\t3 - ВЫХОД" << endl;
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

//-----------------------БАНК----------------------------------
void Menu::SelectBankOperation()
{
    bool run = true;
    while(run)
    {
        out << "выберите команду:" << endl
            << "\t1 - посмотреть все банки" << endl
            << "\t2 - создать новый банк" << endl
            << "\t3 - выбрать банк" << endl
            << "\t4 - ВЫХОД" << endl;
        char command;
        in >> command;
        switch (command)
        {
        case '1':
        {
            Bank_GetAllBanks();
            break;
        }
        case '2':
        {
            Bank_AddNewBank();
            break;
        }
        case '3':
        {
            Bank_ChooseBank(); //пишем имя банка и запускаем Bank_SelectChoosedBankOperation()
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

void Menu::Bank_SelectChoosedBankOperation(const QString& BankName)
{
    bool run = true;
    while(run)
    {
        out << "выберите команду:" << endl
            << "\t1 - удалить банк" << endl
            << "\t2 - посмотреть всех клиентов банка" << endl
            << "\t3 - удалить клиента" << endl
            << "\t4 - выбрать клиента" << endl
            << "\t5 - ВЫХОД" << endl;
        char command;
        in >> command;
        switch (command)
        {
        case '1':
        {
            Bank_RemoveBank();
            break;
        }
        case '2':
        {
            Bank_GetAllClients();
            break;
        }
        case '3':
        {
            Bank_RemoveClient();
            break;
        }
        case '4':
        {
            Bank_ChooseClient();
            break;
        }
        case '5':
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

void Menu::Bank_SelectChoosedClientOperation(const QString& ClientFIO)
{
    bool run = true;
    while(run)
    {
        out << "выберите команду;" << endl
            << "\t1 - посмотреть все карты клиента" << endl
            << "\t2 - удалить карту" << endl
            << "\t3 - выбрать карту" << endl
            << "\t4 - ВЫХОД" << endl;
        char command;
        in >> command;
        switch (command)
        {
        case '1':
        {
            Bank_GetAllCards();
            break;
        }
        case '2':
        {
            Bank_RemoveCard();
            break;
        }
        case '3':
        {
            Bank_ChooseCard();
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

void Menu::Bank_SelectChoosedCardOperation(const unsigned int& CardID)
{
    bool run = true;
    while(run)
    {
        out << "выберите команду:" << endl
            << "\t1 - узнать баланс" << endl
            << "\t2 - ВЫХОД" << endl;
        char command;
        in >> command;
        switch (command)
        {
        case '1':
        {
            Bank_GetBalance();
            break;
        }
        case '2':
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




//------------------------------КЛИЕНТ---------------------------
void Menu::SelectClientOperation()
{
    bool run = true;
    while(run)
    {
        out << "выберите команду" << endl
            << "1 - посмотреть всех клиентов" << endl
            << "2 - создать нового клиента" << endl
            << "3 - выбрать клиента" << endl
            << "4 - ВЫХОД" << endl;
        char command;
        in >> command;
        switch (command)
        {
        case '1':
        {
            Client_GetAllClients();
            break;
        }
        case '2':
        {
            Client_AddNewClient();
            break;
        }
        case '3':
        {
            Client_ChooseClient();
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

void Menu::Client_SelectChoosedClientOperation(const QString& ClientFIO)
{
    bool run = true;
    while(run)
    {
        out << "выберите команду;" << endl
            << "\t1 - удалить клиента" << endl
            << "\t2 - посмотреть все карты клиента" << endl
            << "\t3 - добавить карту" << endl
            << "\t4 - удалить карту" << endl
            << "\t5 - выбрать карту" << endl
            << "\t6 - ВЫХОД" << endl;
        char command;
        in >> command;
        switch (command)
        {
        case '1':
        {
            Client_RemoveClient();
            break;
        }
        case '2':
        {
            Client_GetAllCard();
            break;
        }
        case '3':
        {
            Client_AddCard();
            break;
        }
        case '4':
        {
            Client_RemoveCard();
            break;
        }
        case '5':
        {
            Client_ChooseCard();
            break;
        }
        case '6':
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

void Menu::Client_SelectChoosedCardOperation(const unsigned int& CardID)
{
    bool run = true;
    while(run)
    {
        out << "выберите команду:" << endl
            << "\t1 - узнать баланс" << endl
            << "\t2 - использовать карту" << endl
            << "\t3 - ВЫХОД" << endl;
        char command;
        in >> command;
        switch (command)
        {
        case '1':
        {
            Bank_GetBalance();
            break;
        }
        case '2':
        {
            Client_UseCard();
            break;
        }
        case '3':
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





void Menu::Bank_GetAllBanks()
{

}

void Menu::Bank_AddNewBank()
{

}

void Menu::Bank_ChooseBank()
{

}









void Menu::Client_GetAllClients()
{

}

void Menu::Client_AddNewClient()
{

}

void Menu::Client_ChooseClient()
{

}


