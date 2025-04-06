#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QMap>

#include "card.h"

class Client
{
public:
    Client(QString fio,
           std::function<Card*(QString)>& addNewCard,
           std::function<void(QString, unsigned int)>& removeCard);

    void AddNewCard();
    void DeleteCard(const unsigned int& id);

    double GetCardBalance(const unsigned int& id);
    void UseCard(const unsigned int& id, const double& value);

    bool IsCardBlocked(const unsigned int& id);
    void BlockCard(const unsigned int& id);
    void UnblockCard(const unsigned int& id);

private:
    QString m_fio;
    QMap<unsigned int, Card*> m_cards;

    std::function<Card*(QString)> m_addNewCard;
    std::function<void(QString, unsigned int)> m_removeCard;

    // Не доступен
    Client();
};

#endif // CLIENT_H
