#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QList>

#include "card.h"

class Client
{
public:
    Client(QString fio);

    void AddNewCard();
    void DeleteCard(unsigned int id);

    double GetCardBalance(unsigned int id);
    void UseCard(unsigned int id, double value);

    void BlockCard(unsigned int id);
    void UnblockCard(unsigned int id);

private:
    QString m_fio;
    QList<Card> m_cards;

    // Не доступен
    Client();
};

#endif // CLIENT_H
