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
    QList<QString> GetClientInfo();
    QList<size_t> GetAllClientCards(const QString &fio);

    void AddCard(const QString &fio);
    void RemoveCard(const QString &fio, const size_t& cardId);
    void BlockCard(const QString &fio, const size_t& cardId);
    void UnblockCard(const QString &fio, const size_t& cardId);
    double CheckCardBalance(const QString &fio, const size_t& cardId);

private:
    QMap<QString, Client> m_clients;
    QMap<size_t, Card> m_cards;
};

#endif // BANK_H
