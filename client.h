#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QMap>
#include <QList>

#include "card.h"

class Client
{
public:
    // Не использовать!!!
    // Нужен только для мап!
    Client(){}

    Client(const QString& fio,
           const std::function<void(QString)> addNewCard,
           const std::function<void(QString, size_t)> removeCard);
    Client(const Client& X);
    Client& operator= (const Client& X);

    void AddNewCard();
    void AddNewCard(Card *card);
    void DeleteCard(const size_t& id);

    QList<size_t> GetCardIds();
    double GetCardBalance(const size_t& id);
    void UseCard(const size_t& id, const double& value);

    bool IsCardBlocked(const size_t& id);
    void BlockCard(const size_t& id);
    void UnblockCard(const size_t& id);

private:
    QString m_fio;
    QMap<size_t, Card*> m_cards;

    std::function<void(QString)> m_addNewCard;
    std::function<void(QString, size_t)> m_removeCard;
};

#endif // CLIENT_H
