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

    void Bank_SelectChoosedBankOperation();
    void Bank_SelectChoosedClientOperation();
    void Bank_SelectChoosedCardOperation();

    void Client_SelectChoosedClientOperation();
    void Client_SelectChoosedCardOperation();

    //функции для SelectBankOperation
    void GetAllBanks();
    void AddNewBank();
    void ChooseBank();

    //функции для SelectClientOperation()
    void GetAllClients();
    void AddNewClient();
    void ChooseClient();




    QMap<QString, Bank> m_banks;
    QTextStream out;
    QTextStream in;
};

#endif // MENU_H
