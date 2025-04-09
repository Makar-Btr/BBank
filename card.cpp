#include "card.h"

Card::Card(size_t id) : m_id(id), m_balance(0), m_isBlocked(false) {}

Card::Card(const Card& O) : m_id(O.m_id), m_balance(O.m_balance), m_isBlocked(O.m_isBlocked) {}

Card& Card::operator= (const Card& O)
{
    if(this != &O)
    {
        m_id = O.m_id;
        m_balance = O.m_balance;
        m_isBlocked = O.m_isBlocked;
    }
    return *this;
}


size_t Card::GetID()
{
    return m_id;
}


bool Card::IsBlocked()
{
    return m_isBlocked;
}

void Card::Block()
{
    m_isBlocked = true;
}

void Card::UnBlock()
{
    m_isBlocked = false;
}


double Card::GetBalance()
{
    return m_balance;
}

void Card::UpdateBalance(const double& value)
{
    m_balance += value;
}
