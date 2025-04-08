#include "bank.h"

#include <ctime>
#include <functional>

Bank::Bank() {}


void Bank::AddClient(const QString& fio)
{
    if(m_clients.contains(fio) == false)
    {
        m_clients[fio] = Client(fio,
                                std::bind(&Bank::AddCard, this, std::placeholders::_1),
                                std::bind(&Bank::RemoveCard, this, std::placeholders::_1, std::placeholders::_2));
    }

}

void Bank::RemoveClient(const QString &fio)
{
    if (m_clients.contains(fio))
    {
        QList IDs = m_clients[fio].GetCardIds();
        foreach (size_t id, IDs)
        {
            m_cards.remove(id);
        }
        m_clients.remove(fio);
    }
}

Client Bank::GetClient(const QString& fio)
{
    return m_clients[fio];
}

QList<QString> Bank::GetClientInfo()
{
    return m_clients.keys();
}

QList<size_t> Bank::GetAllClientCards(const QString &fio)
{
    return m_clients[fio].GetCardIds();
}


void Bank::AddCard(const QString &fio)
{
    if(m_clients.contains(fio) == false)
    {
        AddClient(fio);
    }
    size_t newId;
    while (true)
    {
        std::srand(std::time({})); // use current time as seed for random generator
        newId = std::rand();
        if (m_cards.contains(newId) == false)
        {
            break;
        }
    }
    m_cards[newId] = Card(newId);
    m_clients[fio].AddNewCard(&m_cards[newId]);
}

void Bank::RemoveCard(const QString &fio, const size_t& cardId)
{
    if(m_clients.contains(fio))
    {
        if(m_cards.contains(cardId))
        {
            m_clients[fio].DeleteCard(cardId);
            m_cards.remove(cardId);
        }
    }
}

void Bank::BlockCard(const QString &fio, const size_t& cardId)
{
    if(m_clients.contains(fio))
    {
        if(m_cards.contains(cardId))
        {
            m_clients[fio].BlockCard(cardId);
        }
    }
}

void Bank::UnblockCard(const QString &fio, const size_t &cardId)
{
    if(m_clients.contains(fio))
    {
        if(m_cards.contains(cardId))
        {
            m_clients[fio].UnblockCard(cardId);
        }
    }
}

double Bank::CheckCardBalance(const QString &fio, const size_t &cardId)
{
    return m_clients[fio].GetCardBalance(cardId);
}
