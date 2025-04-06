#ifndef MENU_H
#define MENU_H

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
};

#endif // MENU_H
