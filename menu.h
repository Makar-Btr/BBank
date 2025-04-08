#ifndef MENU_H
#define MENU_H

#include <QMap>
#include <QString>
#include <QTextStream>

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
    //функции для Run
    void SelectBankOperation();
    void SelectClientOperation();

    void Bank_SelectChoosedBankOperation(const QString& BankName);
    void Bank_SelectChoosedClientOperation(const QString& ClientFIO);
    void Bank_SelectChoosedCardOperation(const unsigned int& CardID);

    void Client_SelectChoosedClientOperation(const QString& ClientFIO);
    void Client_SelectChoosedCardOperation(const unsigned int& CardID);

    //-----------------------БАНК----------------
    //функции для SelectBankOperation
    void Bank_GetAllBanks();
    void Bank_AddNewBank();
    void Bank_ChooseBank(); //пишем имя банка и запускаем Bank_SelectChoosedBankOperation()

    //функции для Bank_SelectChoosedBankOperation
    void Bank_RemoveBank();
    void Bank_GetAllClients();
    void Bank_RemoveClient();
    void Bank_ChooseClient(); //пишем имя клиента и запускаем Bank_SelectChoosedClientOperation()

    //функции для Bank_SelectChoosedClientOperation
    void Bank_GetAllCards();
    void Bank_RemoveCard();
    void Bank_ChooseCard(); //пишем ID карты и запускаем Bank_SelectChoosedCardOperation()

    //функции для Bank_SelectChoosedCardOperation
    void Bank_GetBalance();


    //----------------------КЛИЕНТ----------------
    //функции для SelectClientOperation
    void Client_GetAllClients();
    void Client_AddNewClient();
    void Client_ChooseClient(); //пишем имя клиента и запускаем Client_SelectChoosedClientOperation()

    //функции для Client_SelectChoosedClientOperation
    void Client_RemoveClient();
    void Client_GetAllCard();
    void Client_AddCard();
    void Client_RemoveCard();
    void Client_ChooseCard(); //пишем ID карты и запускаем Client_SelectChoosedCardOperation()

    //функции для Client_SelectChoosedClientOperation
    void Client_GetBalance();
    void Client_UseCard();

    QMap<QString, Bank> m_banks;
    QTextStream out;
    QTextStream in;
};

#endif // MENU_H
