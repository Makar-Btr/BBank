#ifndef BANK_H
#define BANK_H

#include <QString>
#include <QList>
#include <QMap>

#include "card.h"
#include "client.h"

class Bank
{
public:
    Bank();

    void AddClient(const QString &fio);
    void RemoveClient(const QString &fio);
    QString GetClientInfo(const QString &fio);

    void AddCard(const QString &fio);
    void RemoveCard(const QString &fio, const unsigned int& cardId);
    void BlockCard(const QString &fio, const unsigned int& cardId);

private:
    QMap<QString, Client> m_clients;
    QMap<unsigned int, Card> m_cards;
};

#endif // BANK_H
