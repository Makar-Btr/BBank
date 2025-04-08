#include "client.h"

Client::Client(const QString& fio,
               const std::function<void(QString)> addNewCard,
               const std::function<void(QString, size_t)> removeCard) :
    m_fio(fio), m_addNewCard(addNewCard), m_removeCard(removeCard) {}

Client::Client(const Client& X) :
    m_fio(X.m_fio), m_addNewCard(X.m_addNewCard), m_removeCard(X.m_removeCard) {}

Client& Client::operator= (const Client& X)
{
    if(this != &X)
    {
        m_fio = X.m_fio;
        m_addNewCard = X.m_addNewCard;
        m_removeCard = X.m_removeCard;
    }
    return *this;
}


void Client::AddNewCard()
{
    m_addNewCard(m_fio);
}

void Client::AddNewCard(Card* card)
{
    m_cards[card->GetID()] = card;
}

void Client::DeleteCard(const size_t& id)
{
    if (m_cards.contains(id))
    {
        m_cards.remove(id);
        m_removeCard(m_fio, id);
    }
}

QList<size_t> Client::GetCardIds()
{
    return m_cards.keys();
}

double Client::GetCardBalance(const size_t& id)
{
    return m_cards[id]->GetBalance();
}

void Client::UseCard(const size_t& id, const double& value)
{
    if (IsCardBlocked(id) == false)
    {
        m_cards[id]->UpdateBalance(value);
    }
}

bool Client::IsCardBlocked(const size_t& id)
{
    return m_cards[id]->IsBlocked();
}

void Client::BlockCard(const size_t& id)
{
    if (IsCardBlocked(id) == false)
    {
        m_cards[id]->Block();
    }
}

void Client::UnblockCard(const size_t& id)
{
    if (IsCardBlocked(id))
    {
        m_cards[id]->UnBlock();
    }
}


QList<size_t> Client::GetCardsInfo()
{
    return m_cards.keys();
}
