#ifndef BANK_H
#define BANK_H

#include <QString>
#include <QList>

#include "card.h"
#include "client.h"

class Bank
{
public:
    Bank();

    void AddClient();
    void RemoveClient();
    QString GetClientInfo(QString fio);

    void AddCard(QString fio);
    void RemoveCard(QString fio, unsigned int cardId);
    void BlockCard(QString fio, unsigned int cardId);

private:
    QList<Client> m_clients;
    QList<Card> m_cards;
};

#endif // BANK_H
