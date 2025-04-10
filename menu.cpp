#include "menu.h"

Menu::Menu() : m_in(stdin), m_out(stdout)
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    m_in.setEncoding(QStringConverter::Encoding::System);
    m_out.setEncoding(QStringConverter::Encoding::System);
}

void Menu::Run()
{
    bool run = true;
    while(run)
    {
        m_out << "выберите права доступа:" << endl
              << "\t1 - банк" << endl
              << "\t2 - клиент" << endl
              << "\t3 - ВЫХОД" << endl;
        QString command = GetUserCommand();
        if (command == "1")
        {
            SelectBankOperation();
        }
        else if (command == "2")
        {
            SelectClientOperation();
        }
        else if (command == "3")
        {
            run = false;
        }
        else
        {
            m_out << "неивестная команда" << endl;
        }
    }
}

// Helper method to get user command
QString Menu::GetUserCommand()
{
    QString command;
    m_in >> command;
    return command;
}

// Helper method to display menu options
void Menu::DisplayMenu(const QStringList& options)
{
    for (const auto& option : options)
    {
        m_out << option << endl;
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
        QString command = GetUserCommand();
        if (command == "1")
        {
            Bank_GetAllBanks();
        }
        else if (command == "2")
        {
            Bank_AddNewBank();
        }
        else if (command == "3")
        {
            Bank_ChooseBank();
        }
        else if (command == "4")
        {
            run = false;
        }
        else
        {
            m_out << "неивестная команда" << endl;
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
            "\t3 - добавить клиента",
            "\t4 - удалить клиента",
            "\t5 - выбрать клиента",
            "\t6 - ВЫХОД"
        });
        QString command = GetUserCommand();
        if (command == "1")
        {
            Bank_RemoveBank(BankName);
        }
        else if (command == "2")
        {
            Bank_GetAllClients(BankName);
        }
        else if (command == "3")
        {
            Bank_AddClient(BankName);
        }
        else if (command == "4")
        {
            Bank_RemoveClient(BankName);
        }
        else if (command == "5")
        {
            Bank_ChooseClient(BankName);
        }
        else if (command == "6")
        {
            run = false;
        }
        else
        {
            m_out << "неивестная команда" << endl;
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
        QString command = GetUserCommand();
        if (command == "1")
        {
            Bank_GetAllCards(BankName, ClientFIO);
        }
        else if (command == "2")
        {
            Bank_RemoveCard(BankName, ClientFIO);
        }
        else if (command == "3")
        {
            Bank_ChooseCard(BankName, ClientFIO);
        }
        else if (command == "4")
        {
            run = false;
        }
        else
        {
            m_out << "неивестная команда" << endl;
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
        QString command = GetUserCommand();
        if (command == "1")
        {
            Bank_GetBalance(BankName, ClientFIO, CardID);
        }
        else if (command == "2")
        {
            Bank_BlockCard(BankName, ClientFIO, CardID);
        }
        else if (command == "3")
        {
            Bank_UnblockCard(BankName, ClientFIO, CardID);
        }
        else if (command == "4")
        {
            run = false;
        }
        else
        {
            m_out << "неивестная команда" << endl;
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
            "\t2 - выбрать клиента",
            "\t3 - ВЫХОД"
        });
        QString command = GetUserCommand();
        if (command == "1")
        {
            Client_GetAllClients();
        }
        else if (command == "2")
        {
            Client_ChooseClient();
        }
        else if (command == "3")
        {
            run = false;
        }
        else
        {
            m_out << "неивестная команда" << endl;
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
        QString command = GetUserCommand();
        if (command == "1")
        {
            Client_RemoveClient(ClientFIO);
        }
        else if (command == "2")
        {
            Client_GetAllCard(ClientFIO);
        }
        else if (command == "3")
        {
            Client_AddCard(ClientFIO);
        }
        else if (command == "4")
        {
            Client_RemoveCard(ClientFIO);
        }
        else if (command == "5")
        {
            Client_ChooseCard(ClientFIO);
        }
        else if (command == "6")
        {
            run = false;
        }
        else
        {
            m_out << "неивестная команда" << endl;
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
            "\t3 - заблокировать карту",
            "\t4 - разблокировать карту",
            "\t5 - ВЫХОД"
        });
        QString command = GetUserCommand();
        if (command == "1")
        {
            Bank_GetBalance(BankName, ClientFIO, CardID);
        }
        else if (command == "2")
        {
            Client_UseCard(BankName, ClientFIO, CardID);
        }
        else if (command == "3")
        {
            Bank_BlockCard(BankName, ClientFIO, CardID);
        }
        else if (command == "4")
        {
            Bank_UnblockCard(BankName, ClientFIO, CardID);
        }
        else if (command == "5")
        {
            run = false;
        }
        else
        {
            m_out << "неивестная команда" << endl;
        }
    }
}



//скрытые функции банка
QList<QString> Menu::Bank_GetAllBanks()
{
    QList<QString> BankNames = m_banks.keys();
    for (int i = 0; i < BankNames.size(); i++)
    {
        m_out << i + 1 << " " << BankNames[i] << endl;
    }
    return BankNames;
}

void Menu::Bank_AddNewBank()
{
    QString NewBankName;
    m_out << "введите имя банка:" << endl;
    while(true)
    {

        m_in >> NewBankName;
        if(m_banks.contains(NewBankName) == false)
        {
            break;
        }
        else
        {
            m_out << "Название уже занято. Пожалуйста, выберите другое" << endl;
        }
    }
    m_banks[NewBankName] = Bank();
}

void Menu::Bank_ChooseBank()
{
    m_out << "выберите банк (порядковый номер)" << endl;
    QList<QString> Banks = Bank_GetAllBanks();
    size_t BankNumber;
    m_in >> BankNumber;
    if(BankNumber > Banks.size())
    {
        m_out << "такого банка нет. пожалуйста, введите другой номер" << endl;
        Bank_ChooseBank();
        return;
    }
    Bank_SelectChoosedBankOperation(Banks[BankNumber - 1]);
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
        m_out << i + 1 << " " << Clients[i] << endl;
    }
    return Clients;
}

// Helper method to select a client by its index
size_t Menu::SelectClient(const QList<QString>& Clients, const QString& prompt)
{
    while (true)
    {
        m_out << prompt << endl;
        for (int i = 0; i < Clients.size(); i++)
        {
            m_out << i + 1 << " " << Clients[i] << endl;
        }
        size_t ClientNumber;
        m_in >> ClientNumber;
        if (ClientNumber > 0 && ClientNumber <= Clients.size())
        {
            return ClientNumber - 1; // Convert to zero-based index
        }
        m_out << "такого клиента нет. пожалуйста, введите другой номер" << endl;
    }
}

void Menu::Bank_AddClient(const QString& BankName)
{
    QString ClientFIO;
    m_out << "введите ФИО клиента" << endl;
    m_in >> ClientFIO;
    QList<QString> Clients = m_banks[BankName].GetClientInfo();
    if(Clients.contains(ClientFIO) == false)
    {
        m_banks[BankName].AddClient(ClientFIO);
    }
}

void Menu::Bank_RemoveClient(const QString& BankName)
{
    QList<QString> Clients = Bank_GetAllClients(BankName);
    if (Clients.isEmpty())
    {
        m_out << "Список клиентов пуст. Операция невозможна." << endl;
        return;
    }
    size_t ClientIndex = SelectClient(Clients, "выберите клиента (порядковый номер)");
    if(ClientIndex >= Clients.size())
        return
    m_banks[BankName].RemoveClient(Clients[ClientIndex]);
}

void Menu::Bank_ChooseClient(const QString& BankName)
{
    QList<QString> Clients = Bank_GetAllClients(BankName);
    if (Clients.isEmpty())
    {
        m_out << "Список клиентов пуст. Операция невозможна." << endl;
        return;
    }
    size_t ClientIndex = SelectClient(Clients, "выберите клиента (порядковый номер)");
    Bank_SelectChoosedClientOperation(BankName, Clients[ClientIndex]);
}


QList<size_t> Menu::Bank_GetAllCards(const QString& BankName, const QString& ClientFIO)
{
    QList<size_t> Cards = m_banks[BankName].GetAllClientCards(ClientFIO);
    for(int i = 0; i < Cards.size(); i++)
    {
        m_out << i + 1 << " " << Cards[i] << endl;
    }
    return Cards;
}

// Helper method to select a card by its index
size_t Menu::SelectCard(const QList<size_t>& Cards, const QString& prompt)
{
    while (true)
    {
        m_out << prompt << endl;
        for (int i = 0; i < Cards.size(); i++)
        {
            m_out << i + 1 << " " << Cards[i] << endl;
        }
        size_t CardNumber;
        m_in >> CardNumber;
        if (CardNumber > 0 && CardNumber <= Cards.size())
        {
            return CardNumber - 1; // Convert to zero-based index
        }
        m_out << "такой карты нет. пожалуйста, введите другой номер" << endl;
    }
}

void Menu::Bank_RemoveCard(const QString& BankName, const QString& ClientFIO)
{
    QList<size_t> Cards = Bank_GetAllCards(BankName, ClientFIO);
    if (Cards.isEmpty())
    {
        m_out << "Список карт пуст. Операция невозможна." << endl;
        return;
    }
    size_t CardIndex = SelectCard(Cards, "выберите карту (порядковый номер)");
    m_banks[BankName].RemoveCard(ClientFIO, Cards[CardIndex]);
}

void Menu::Bank_ChooseCard(const QString& BankName, const QString& ClientFIO)
{
    QList<size_t> Cards = Bank_GetAllCards(BankName, ClientFIO);
    if (Cards.isEmpty())
    {
        m_out << "Список карт пуст. Операция невозможна." << endl;
        return;
    }
    size_t CardIndex = SelectCard(Cards, "выберите карту (порядковый номер)");
    Bank_SelectChoosedCardOperation(BankName, ClientFIO, Cards[CardIndex]);
}

void Menu::Bank_GetBalance(const QString& BankName,
                           const QString& ClientFIO,
                           const size_t& CardID)
{
    m_out << m_banks[BankName].CheckCardBalance(ClientFIO, CardID);
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
QList<QString> Menu::Client_GetAllClients()
{
    QList<QString> Clients;
    foreach(Bank bank, m_banks)
    {
        Clients += bank.GetClientInfo();
    }
    for(int i = 0; i < Clients.size(); i++)
    {
        m_out << i + 1 << " " << Clients[i] << endl;
    }
    return Clients;
}

void Menu::Client_ChooseClient()
{
    QList<QString> Clients = Client_GetAllClients();
    if (Clients.isEmpty())
    {
        m_out << "Список клиентов пуст. Операция невозможна." << endl;
        return;
    }
    m_out << "выберите клиента (порядковый номер)" << endl;
    size_t ClientNumber;
    m_in >> ClientNumber;
    if(ClientNumber > Clients.size())
    {
        m_out << "такого клиента нет. пожалуйста, введите другой номер" << endl;
        Client_ChooseClient();
        return;
    }
    Client_SelectChoosedClientOperation(Clients[ClientNumber-1]);
}


QList<QString> Menu::WhichBanksClient(const QString& ClientFIO)
{
    QList<QString> Client_of_Banks;
    QList<QString> BankClients;
    foreach(Bank bank, m_banks)
    {
        BankClients = bank.GetClientInfo();
        for(int i = 0; i < BankClients.size(); i++)
        {
            if(ClientFIO == BankClients[i])
            {
                Client_of_Banks.push_back(m_banks.key(bank));
            }
        }
    }
    return Client_of_Banks;
}

void Menu::Client_RemoveClient(const QString& ClientFIO)
{
    QList<QString> Client_of_Banks = WhichBanksClient(ClientFIO);
    if (Client_of_Banks.isEmpty())
    {
        m_out << " не является клиентом банков. Операция невозможна." << endl;
        return;
    }
    m_out << ClientFIO << " является клиентом" << endl;
    for(int i = 0; i < Client_of_Banks.size(); i++)
    {
        m_out << i + 1 << " " << Client_of_Banks[i] << endl;
    }
    m_out << "выберите банк (порядковый номер) для проведения операции" << endl;
    size_t BankNumber;
    m_in >> BankNumber;
    if(BankNumber > Client_of_Banks.size())
    {
        m_out << "такого банка нет. пожалуйста, введите другой номер" << endl;
        Client_RemoveClient(ClientFIO);
        return;
    }
    m_banks[Client_of_Banks[BankNumber-1]].RemoveClient(ClientFIO);
}

void Menu::Client_GetAllCard(const QString& ClientFIO)
{
    QList<QString> Client_of_Banks = WhichBanksClient(ClientFIO);
    if (Client_of_Banks.isEmpty())
    {
        m_out << ClientFIO << " не является клиентом банков. Операция невозможна." << endl;
        return;
    }
    m_out << ClientFIO << " является клиентом" << endl;
    for(int i = 0; i < Client_of_Banks.size(); i++)
    {
        m_out << i + 1 << " " << Client_of_Banks[i] << endl;
    }
    m_out << "выберите банк (порядковый номер) для проведения операции" << endl;
    size_t BankNumber;
    m_in >> BankNumber;
    if(BankNumber > Client_of_Banks.size())
    {
        m_out << "такого банка нет. пожалуйста, введите другой номер" << endl;
        Client_GetAllCard(ClientFIO);
        return;
    }
    QList<size_t> ClientCards = m_banks[Client_of_Banks[BankNumber-1]].GetAllClientCards(ClientFIO);
    for(int i = 0; i < ClientCards.size(); i++)
    {
        m_out << i + 1 << " " << ClientCards[i] << endl;
    }
}

void Menu::Client_AddCard(const QString& ClientFIO)
{
    QList<QString> Client_of_Banks = WhichBanksClient(ClientFIO);
    if (Client_of_Banks.isEmpty())
    {
        m_out << ClientFIO << " не является клиентом банков. Операция невозможна." << endl;
        return;
    }
    m_out << ClientFIO << " является клиентом" << endl;
    for(int i = 0; i < Client_of_Banks.size(); i++)
    {
        m_out << i + 1 << " " << Client_of_Banks[i] << endl;
    }
    m_out << "выберите банк (порядковый номер) для проведения операции" << endl;
    size_t BankNumber;
    m_in >> BankNumber;
    if(BankNumber > Client_of_Banks.size())
    {
        m_out << "такого банка нет. пожалуйста, введите другой номер" << endl;
        Client_GetAllCard(ClientFIO);
        return;
    }
    m_banks[Client_of_Banks[BankNumber-1]].AddCard(ClientFIO);
}

void Menu::Client_RemoveCard(const QString& ClientFIO)
{
    QList<QString> Client_of_Banks = WhichBanksClient(ClientFIO);
    if (Client_of_Banks.isEmpty())
    {
        m_out << ClientFIO << " не является клиентом банков. Операция невозможна." << endl;
        return;
    }
    m_out << ClientFIO << " является клиентом" << endl;
    for(int i = 0; i < Client_of_Banks.size(); i++)
    {
        m_out << i + 1 << " " << Client_of_Banks[i] << endl;
    }
    m_out << "выберите банк (порядковый номер) для проведения операции" << endl;
    size_t BankNumber;
    m_in >> BankNumber;
    if(BankNumber > Client_of_Banks.size())
    {
        m_out << "такого банка нет" << endl;
        Client_GetAllCard(ClientFIO);
        return;
    }
    m_out << "выберите карту (порядковый номер) для проведения операции" << endl;
    QList<size_t> ClientCards = m_banks[Client_of_Banks[BankNumber-1]].GetAllClientCards(ClientFIO);
    for(int i = 0; i < ClientCards.size(); i++)
    {
        m_out << i + 1 << " " << ClientCards[i] << endl;
    }
    size_t CardNumber;
    m_in >> CardNumber;
    if(CardNumber > ClientCards.size())
    {
        m_out << "такой карты нет" << endl;
        Client_GetAllCard(ClientFIO);
        return;
    }
    m_banks[Client_of_Banks[BankNumber-1]].RemoveCard(ClientFIO, CardNumber-1);
}

void Menu::Client_ChooseCard(const QString& ClientFIO)
{
    QList<QString> Client_of_Banks = WhichBanksClient(ClientFIO);
    if (Client_of_Banks.isEmpty())
    {
        m_out << ClientFIO << " не является клиентом банков. Операция невозможна." << endl;
        return;
    }
    m_out << ClientFIO << " является клиентом" << endl;
    for(int i = 0; i < Client_of_Banks.size(); i++)
    {
        m_out << i + 1 << " " << Client_of_Banks[i] << endl;
    }
    m_out << "выберите банк (порядковый номер) для проведения операции" << endl;
    size_t BankNumber;
    m_in >> BankNumber;
    if(BankNumber > Client_of_Banks.size())
    {
        m_out << "такого банка нет" << endl;
        Client_GetAllCard(ClientFIO);
        return;
    }
    m_out << "выберите карту (порядковый номер) для проведения операции" << endl;
    QList<size_t> ClientCards = m_banks[Client_of_Banks[BankNumber-1]].GetAllClientCards(ClientFIO);
    for(int i = 0; i < ClientCards.size(); i++)
    {
        m_out << i + 1 << " " << ClientCards[i] << endl;
    }
    size_t CardNumber;
    m_in >> CardNumber;
    if(CardNumber > ClientCards.size())
    {
        m_out << "такой карты нет" << endl;
        Client_GetAllCard(ClientFIO);
        return;
    }
    Client_SelectChoosedCardOperation(Client_of_Banks[BankNumber-1],
                                      ClientFIO,
                                      ClientCards[CardNumber-1]);
}


void Menu::Client_UseCard(const QString& BankName,
                          const QString& ClientFIO,
                          const size_t& CardID)
{
    if(m_banks[BankName].GetClient(ClientFIO).IsCardBlocked(CardID))
    {
        m_out << "карта заблокирована. операция недоступна" << endl;
        return;
    }
    m_out << "введите сумму (положитеное - добавить, отрицательное - снять" << endl;
    double value;
    m_in >> value;
    m_banks[BankName].GetClient(ClientFIO).UseCard(CardID, value);
}

