#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QList>

#include "card.h"

class Client
{
public:
    Client(QString fio,
           std::function<void(QString)>* addNewCard,
           std::function<void(QString, unsigned int)>* removeCard);

    void AddNewCard(Card* card);
    void DeleteCard(const unsigned int& id);

    double GetCardBalance(const unsigned int& id);
    void UseCard(const unsigned int& id, const double& value);

    void BlockCard(const unsigned int& id);
    void UnblockCard(const unsigned int& id);

private:
    QString m_fio;
    QList<Card*> m_cards;

    std::function<void(QString)>* m_addNewCard;
    std::function<void(QString, unsigned int)>* m_removeCard;

    // Не доступен
    Client();
};

#endif // CLIENT_H
