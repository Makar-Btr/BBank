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
            Bank_RemoveBank(BankName);
            break;
        }
        case '2':
        {
            Bank_GetAllClients(BankName);
            break;
        }
        case '3':
        {
            Bank_RemoveClient(BankName);
            break;
        }
        case '4':
        {
            Bank_ChooseClient(BankName);
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

void Menu::Bank_SelectChoosedClientOperation(const QString& BankName, const QString& ClientFIO)
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
            Bank_GetAllCards(BankName, ClientFIO);
            break;
        }
        case '2':
        {
            Bank_RemoveCard(BankName, ClientFIO);
            break;
        }
        case '3':
        {
            Bank_ChooseCard(BankName, ClientFIO);
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

void Menu::Bank_SelectChoosedCardOperation(const QString& BankName,
                                           const QString& ClientFIO,
                                           const size_t& CardID)
{
    bool run = true;
    while(run)
    {
        out << "выберите команду:" << endl
            << "\t1 - узнать баланс" << endl
            << "\t2 - заблокировать" << endl
            << "\t3 - разблокировать" << endl
            << "\t4 - ВЫХОД" << endl;
        char command;
        in >> command;
        switch (command)
        {
        case '1':
        {
            Bank_GetBalance(BankName,ClientFIO,CardID);
            break;
        }
        case '2':
        {
            Bank_BlockCard(BankName,ClientFIO,CardID);
            break;
        }
        case '3':
        {
            Bank_UnblockCard(BankName,ClientFIO,CardID);
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


//------------------------------КЛИЕНТ---------------------------
void Menu::SelectClientOperation()
{
    bool run = true;
    while(run)
    {
        out << "выберите команду" << endl
            << "\t1 - посмотреть всех клиентов" << endl
            << "\t2 - создать нового клиента" << endl
            << "\t3 - выбрать клиента" << endl
            << "\t4 - ВЫХОД" << endl;
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

void Menu::Client_SelectChoosedCardOperation(const QString& BankName,
                                             const QString& ClientFIO,
                                             const size_t& CardID)
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
            Bank_GetBalance(BankName,ClientFIO,CardID);
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



//скрытые функции банка
QList<QString> Menu::Bank_GetAllBanks()
{
    QList<QString> BankNames = m_banks.keys();
    for (int i = 0; i < BankNames.size(); i++)
    {
        out << i + 1 << " " << BankNames[i] << endl;
    }
    return BankNames;
}

void Menu::Bank_AddNewBank()
{
    QString NewBankName;
    while(true)
    {
        out << "введите имя банка";
        in >> NewBankName;
        if(m_banks.contains(NewBankName) == false)
        {
            break;
        }
        else
        {
            out << "Название уже занято. Пожалуйста, выберите другое";
        }
    }
    m_banks[NewBankName] = Bank();
}

void Menu::Bank_ChooseBank()
{
    out << "выберите банк (порядковый номер)" << endl;
    QList<QString> Banks = Bank_GetAllBanks();
    size_t BankNumber;
    in >> BankNumber;
    if(BankNumber >= Banks.size())
    {
        out << "такого банка нет. пожалуйста, введите другой номер";
        Bank_ChooseBank();
        return;
    }
    Bank_SelectChoosedBankOperation(Banks[BankNumber]);
}


void Menu::Bank_RemoveBank(const QString& BankName)
{
    m_banks.remove(BankName);
}

QList<QString> Menu::Bank_GetAllClients(const QString& BankName)
{
    QList<QString> Clients = m_banks[BankName].GetClientInfo();
    for (int i = 0; i < Clients.size(); i++)
    {
        out << i + 1 << " " << Clients[i] << endl;
    }
    return Clients;
}

void Menu::Bank_RemoveClient(const QString& BankName)
{
    out << "выберите клиента (порядковый номер)" << endl;
    QList<QString> Clients = Bank_GetAllClients(BankName);
    size_t ClientNumber;
    in >> ClientNumber;
    if(ClientNumber >= Clients.size())
    {
        out << "такого клиента нет. пожалуйста, введите другой номер";
        Bank_RemoveClient(BankName);
        return;
    }
    m_banks[BankName].RemoveClient(Clients[ClientNumber]);
}

void Menu::Bank_ChooseClient(const QString& BankName)
{
    out << "выберите клиента (порядковый номер)" << endl;
    QList<QString> Clients = Bank_GetAllClients(BankName);
    size_t ClientNumber;
    in >> ClientNumber;
    if(ClientNumber >= Clients.size())
    {
        out << "такого клиента нет. пожалуйста, введите другой номер";
        Bank_ChooseClient(BankName);
        return;
    }
    Bank_SelectChoosedClientOperation(BankName, Clients[ClientNumber]);
}


QList<size_t> Menu::Bank_GetAllCards(const QString& BankName, const QString& ClientFIO)
{
    QList<size_t> Cards = m_banks[BankName].GetAllClientCards(ClientFIO);
    for(int i = 0; i < Cards.size(); i++)
    {
        out << i + 1 << " " << Cards[i] << endl;
    }
    return Cards;
}

void Menu::Bank_RemoveCard(const QString& BankName, const QString& ClientFIO)
{
    out << "выберите карту (порядковый номер)" << endl;
    QList<size_t> Cards = Bank_GetAllCards(BankName, ClientFIO);
    size_t CardNumber;
    in >> CardNumber;
    if(CardNumber >= Cards.size())
    {
        out << "такой карты нет. пожалуйста, введите другой номер";
        Bank_RemoveClient(BankName);
        return;
    }
    m_banks[ClientFIO].RemoveCard(ClientFIO, CardNumber);
}

void Menu::Bank_ChooseCard(const QString& BankName, const QString& ClientFIO)
{
    out << "выберите карту (порядковый номер)" << endl;
    QList<size_t> Cards = Bank_GetAllCards(BankName, ClientFIO);
    size_t CardNumber;
    in >> CardNumber;
    if(CardNumber >= Cards.size())
    {
        out << "такой карты нет. пожалуйста, введите другой номер";
        Bank_RemoveClient(BankName);
        return;
    }
    Bank_SelectChoosedCardOperation(BankName, ClientFIO, CardNumber);
}


void Menu::Bank_GetBalance(const QString& BankName,
                           const QString& ClientFIO,
                           const size_t& CardID)
{
    out << m_banks[BankName].CheckCardBalance(ClientFIO, CardID);
}

void Menu::Bank_BlockCard(const QString& BankName,
                          const QString& ClientFIO,
                          const size_t& CardID)
{
    m_banks[BankName].BlockCard(ClientFIO, CardID);
}

void Menu::Bank_UnblockCard(const QString& BankName,
                            const QString& ClientFIO,
                            const size_t& CardID)
{
    m_banks[BankName].UnblockCard(ClientFIO, CardID);
}



//скрытые функции клиента
void Menu::Client_GetAllClients()
{

}

void Menu::Client_AddNewClient()
{

}

void Menu::Client_ChooseClient()
{

}


void Menu::Client_RemoveClient()
{

}

void Menu::Client_GetAllCard()
{

}

void Menu::Client_AddCard()
{

}

void Menu::Client_RemoveCard()
{

}

void Menu::Client_ChooseCard()
{

}


void Menu::Client_GetBalance()
{

}

void Menu::Client_UseCard()
{

}


