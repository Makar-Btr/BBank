#include "client.h"

Client::Client(QString fio,
               std::function<Card*(QString)>& addNewCard,
               std::function<void(QString, unsigned int)>& removeCard) :
    m_fio(fio), m_addNewCard(addNewCard), m_removeCard(removeCard) {}


void Client::AddNewCard()
{
    Card* card = m_addNewCard(m_fio);
    m_cards[card->GetID()] = card;
}

void Client::DeleteCard(const unsigned int& id)
{
    m_cards.remove(id);
    m_removeCard(m_fio, id);
}


double Client::GetCardBalance(const unsigned int& id)
{
    return m_cards[id]->GetBalance();
}

void Client::UseCard(const unsigned int& id, const double& value)
{
    if (IsCardBlocked(id) == false)
    {
        m_cards[id]->UpdateBalance(value);
    }
}

bool Client::IsCardBlocked(const unsigned int& id)
{
    return m_cards[id]->IsBlocked();
}

void Client::BlockCard(const unsigned int& id)
{
    if (IsCardBlocked(id) == false)
    {
        m_cards[id]->Block();
    }
}

void Client::UnblockCard(const unsigned int& id)
{
    if (IsCardBlocked(id))
    {
        m_cards[id]->UnBlock();
    }
}
