#ifndef MENU_H
#define MENU_H

#include <QMap>
#include <QString>

#include "bank.h"

class Menu
{
public:
    Menu();

    // Метод с бесконечным циклом
    // Метод предлагает выбрать, будет работать программа от лица банка или клиента.
    // Метод предоставляет возможность выключить программу по средством выбора пункта меню.
    void Run();

protected:
    void SelectBankOperation();
    void SelectClientOperation();

private:
    QMap<QString, Bank> m_banks;
};

#endif // MENU_H
