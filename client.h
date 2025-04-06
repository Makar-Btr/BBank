#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QMap>
#include <QList>

#include "card.h"

class Client
{
public:
    Client(const QString& fio,
           const std::function<void(QString)> addNewCard,
           const std::function<void(QString, unsigned int)> removeCard);
    Client(const Client& X);
    Client& operator= (const Client& X);

    void AddNewCard();
    void AddNewCard(Card *card);
    void DeleteCard(const unsigned int& id);

    QList<unsigned int> GetCardIds();
    double GetCardBalance(const unsigned int& id);
    void UseCard(const unsigned int& id, const double& value);

    bool IsCardBlocked(const unsigned int& id);
    void BlockCard(const unsigned int& id);
    void UnblockCard(const unsigned int& id);

private:
    QString m_fio;
    QMap<unsigned int, Card*> m_cards;

    std::function<void(QString)> m_addNewCard;
    std::function<void(QString, unsigned int)> m_removeCard;

    // Не доступен
    Client();
};

#endif // CLIENT_H
