#ifndef MENU_H
#define MENU_H

#include <QMap>
#include <QString>
#include <QTextStream>
#include <windows.h>

#include "bank.h"

using namespace Qt;

class Menu
{
public:
    Menu();

    // Метод с бесконечным циклом
    // Метод предлагает выбрать, будет работать программа от лица банка или клиента.
    // Метод предоставляет возможность выключить программу по средством выбора пункта меню.
    void Run();

private:
    // Helper methods
    QString GetUserCommand();
    void DisplayMenu(const QStringList& options);
    size_t SelectCard(const QList<size_t>& Cards, const QString& prompt);
    size_t SelectClient(const QList<QString>& Clients, const QString& prompt);
    QList<QString> WhichBanksClient(const QString& ClientFIO);

    //функции для Run
    void SelectBankOperation();
    void SelectClientOperation();

    void Bank_SelectChoosedBankOperation(const QString& BankName);
    void Bank_SelectChoosedClientOperation(const QString& BankName, const QString& ClientFIO);
    void Bank_SelectChoosedCardOperation(const QString& BankName,
                                         const QString& ClientFIO,
                                         const size_t& CardID);

    void Client_SelectChoosedClientOperation(const QString& ClientFIO);
    void Client_SelectChoosedCardOperation(const QString& BankName,
                                           const QString& ClientFIO,
                                           const size_t& CardID);

    //-----------------------БАНК----------------
    //функции для SelectBankOperation
    QList<QString> Bank_GetAllBanks();
    void Bank_AddNewBank();
    void Bank_ChooseBank(); //пишем имя банка и запускаем Bank_SelectChoosedBankOperation()

    //функции для Bank_SelectChoosedBankOperation
    void Bank_RemoveBank(const QString& BankName);
    QList<QString> Bank_GetAllClients(const QString& BankName);
    void Bank_RemoveClient(const QString& BankName);
    void Bank_ChooseClient(const QString& BankName); //пишем имя клиента и запускаем Bank_SelectChoosedClientOperation()

    //функции для Bank_SelectChoosedClientOperation
    QList<size_t> Bank_GetAllCards(const QString& BankName, const QString& ClientFIO);
    void Bank_RemoveCard(const QString& BankName, const QString& ClientFIO);
    void Bank_ChooseCard(const QString& BankName, const QString& ClientFIO); //пишем ID карты и запускаем Bank_SelectChoosedCardOperation()

    //функции для Bank_SelectChoosedCardOperation
    void Bank_GetBalance(const QString& BankName,
                         const QString& ClientFIO,
                         const size_t& CardID);
    void Bank_BlockCard(const QString& BankName,
                         const QString& ClientFIO,
                         const size_t& CardID);
    void Bank_UnblockCard(const QString& BankName,
                        const QString& ClientFIO,
                        const size_t& CardID);


    //----------------------КЛИЕНТ----------------
    //функции для SelectClientOperation
    QList<QString> Client_GetAllClients();
    void Client_ChooseClient(); //пишем имя клиента и запускаем Client_SelectChoosedClientOperation()

    //функции для Client_SelectChoosedClientOperation
    void Client_RemoveClient(const QString& ClientFIO);
    void Client_GetAllCard(const QString& ClientFIO);
    void Client_AddCard(const QString& ClientFIO);
    void Client_RemoveCard(const QString& ClientFIO);
    void Client_ChooseCard(const QString& ClientFIO); //пишем ID карты и запускаем Client_SelectChoosedCardOperation()

    //функции для Client_SelectChoosedClientOperation
    void Client_UseCard(const QString& BankName,
                        const QString& ClientFIO,
                        const size_t& CardID);

    QMap<QString, Bank> m_banks;
    QTextStream m_out;
    QTextStream m_in;
};

#endif // MENU_H
