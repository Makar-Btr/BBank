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
        char command = GetUserCommand();
        switch (command)
        {
        case '1':
            SelectBankOperation();
            break;
        case '2':
            SelectClientOperation();
            break;
        case '3':
            run = false;
            break;
        case '^':
            out << "Уходи, тебя сюда не приглашали!";
            break;
        default:
            out << "неивестная команда";
            break;
        }
    }
}

// Helper method to get user command
char Menu::GetUserCommand()
{
    char command;
    in >> command;
    return command;
}

// Helper method to display menu options
void Menu::DisplayMenu(const QStringList& options)
{
    for (const auto& option : options)
    {
        out << option << endl;
    }
}

//-----------------------БАНК----------------------------------
void Menu::SelectBankOperation()
{
    bool run = true;
    while(run)
    {
        DisplayMenu({
            "выберите команду:",
            "\t1 - посмотреть все банки",
            "\t2 - создать новый банк",
            "\t3 - выбрать банк",
            "\t4 - ВЫХОД"
        });
        char command = GetUserCommand();
        switch (command)
        {
        case '1':
            Bank_GetAllBanks();
            break;
        case '2':
            Bank_AddNewBank();
            break;
        case '3':
            Bank_ChooseBank();
            break;
        case '4':
            run = false;
            break;
        default:
            out << "неивестная команда";
            break;
        }
    }
}

void Menu::Bank_SelectChoosedBankOperation(const QString& BankName)
{
    bool run = true;
    while(run)
    {
        DisplayMenu({
            "выберите команду:",
            "\t1 - удалить банк",
            "\t2 - посмотреть всех клиентов банка",
            "\t3 - удалить клиента",
            "\t4 - выбрать клиента",
            "\t5 - ВЫХОД"
        });
        char command = GetUserCommand();
        switch (command)
        {
        case '1':
            Bank_RemoveBank(BankName);
            break;
        case '2':
            Bank_GetAllClients(BankName);
            break;
        case '3':
            Bank_RemoveClient(BankName);
            break;
        case '4':
            Bank_ChooseClient(BankName);
            break;
        case '5':
            run = false;
            break;
        default:
            out << "неивестная команда";
            break;
        }
    }
}

void Menu::Bank_SelectChoosedClientOperation(const QString& BankName, const QString& ClientFIO)
{
    bool run = true;
    while(run)
    {
        DisplayMenu({
            "выберите команду;",
            "\t1 - посмотреть все карты клиента",
            "\t2 - удалить карту",
            "\t3 - выбрать карту",
            "\t4 - ВЫХОД"
        });
        char command = GetUserCommand();
        switch (command)
        {
        case '1':
            Bank_GetAllCards(BankName, ClientFIO);
            break;
        case '2':
            Bank_RemoveCard(BankName, ClientFIO);
            break;
        case '3':
            Bank_ChooseCard(BankName, ClientFIO);
            break;
        case '4':
            run = false;
            break;
        default:
            out << "неивестная команда";
            break;
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
        DisplayMenu({
            "выберите команду:",
            "\t1 - узнать баланс",
            "\t2 - заблокировать",
            "\t3 - разблокировать",
            "\t4 - ВЫХОД"
        });
        char command = GetUserCommand();
        switch (command)
        {
        case '1':
            Bank_GetBalance(BankName,ClientFIO,CardID);
            break;
        case '2':
            Bank_BlockCard(BankName,ClientFIO,CardID);
            break;
        case '3':
            Bank_UnblockCard(BankName,ClientFIO,CardID);
            break;
        case '4':
            run = false;
            break;
        default:
            out << "неивестная команда";
            break;
        }
    }
}


//------------------------------КЛИЕНТ---------------------------
void Menu::SelectClientOperation()
{
    bool run = true;
    while(run)
    {
        DisplayMenu({
            "выберите команду",
            "\t1 - посмотреть всех клиентов",
            "\t2 - создать нового клиента",
            "\t3 - выбрать клиента",
            "\t4 - ВЫХОД"
        });
        char command = GetUserCommand();
        switch (command)
        {
        case '1':
            Client_GetAllClients();
            break;
        case '2':
            Client_AddNewClient();
            break;
        case '3':
            Client_ChooseClient();
            break;
        case '4':
            run = false;
            break;
        default:
            out << "неивестная команда";
            break;
        }
    }
}

void Menu::Client_SelectChoosedClientOperation(const QString& ClientFIO)
{
    bool run = true;
    while(run)
    {
        DisplayMenu({
            "выберите команду;",
            "\t1 - удалить клиента",
            "\t2 - посмотреть все карты клиента",
            "\t3 - добавить карту",
            "\t4 - удалить карту",
            "\t5 - выбрать карту",
            "\t6 - ВЫХОД"
        });
        char command = GetUserCommand();
        switch (command)
        {
        case '1':
            Client_RemoveClient();
            break;
        case '2':
            Client_GetAllCard();
            break;
        case '3':
            Client_AddCard();
            break;
        case '4':
            Client_RemoveCard();
            break;
        case '5':
            Client_ChooseCard();
            break;
        case '6':
            run = false;
            break;
        default:
            out << "неивестная команда";
            break;
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
        DisplayMenu({
            "выберите команду:",
            "\t1 - узнать баланс",
            "\t2 - использовать карту",
            "\t3 - ВЫХОД"
        });
        char command = GetUserCommand();
        switch (command)
        {
        case '1':
            Bank_GetBalance(BankName,ClientFIO,CardID);
            break;
        case '2':
            Client_UseCard();
            break;
        case '3':
            run = false;
            break;
        default:
            out << "неивестная команда";
            break;
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

// Helper method to select a client by its index
size_t Menu::SelectClient(const QList<QString>& Clients, const QString& prompt)
{
    while (true)
    {
        out << prompt << endl;
        for (int i = 0; i < Clients.size(); i++)
        {
            out << i + 1 << " " << Clients[i] << endl;
        }
        size_t ClientNumber;
        in >> ClientNumber;
        if (ClientNumber > 0 && ClientNumber <= Clients.size())
        {
            return ClientNumber - 1; // Convert to zero-based index
        }
        out << "такого клиента нет. пожалуйста, введите другой номер" << endl;
    }
}

void Menu::Bank_RemoveClient(const QString& BankName)
{
    QList<QString> Clients = Bank_GetAllClients(BankName);
    size_t ClientIndex = SelectClient(Clients, "выберите клиента (порядковый номер)");
    m_banks[BankName].RemoveClient(Clients[ClientIndex]);
}

void Menu::Bank_ChooseClient(const QString& BankName)
{
    QList<QString> Clients = Bank_GetAllClients(BankName);
    size_t ClientIndex = SelectClient(Clients, "выберите клиента (порядковый номер)");
    Bank_SelectChoosedClientOperation(BankName, Clients[ClientIndex]);
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

// Helper method to select a card by its index
size_t Menu::SelectCard(const QList<size_t>& Cards, const QString& prompt)
{
    while (true)
    {
        out << prompt << endl;
        for (int i = 0; i < Cards.size(); i++)
        {
            out << i + 1 << " " << Cards[i] << endl;
        }
        size_t CardNumber;
        in >> CardNumber;
        if (CardNumber > 0 && CardNumber <= Cards.size())
        {
            return CardNumber - 1; // Convert to zero-based index
        }
        out << "такой карты нет. пожалуйста, введите другой номер" << endl;
    }
}

void Menu::Bank_RemoveCard(const QString& BankName, const QString& ClientFIO)
{
    QList<size_t> Cards = Bank_GetAllCards(BankName, ClientFIO);
    size_t CardIndex = SelectCard(Cards, "выберите карту (порядковый номер)");
    m_banks[BankName].RemoveCard(ClientFIO, Cards[CardIndex]);
}

void Menu::Bank_ChooseCard(const QString& BankName, const QString& ClientFIO)
{
    QList<size_t> Cards = Bank_GetAllCards(BankName, ClientFIO);
    size_t CardIndex = SelectCard(Cards, "выберите карту (порядковый номер)");
    Bank_SelectChoosedCardOperation(BankName, ClientFIO, Cards[CardIndex]);
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


