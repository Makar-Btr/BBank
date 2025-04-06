#include "card.h"

Card::Card(unsigned int id) : m_id(id), m_balance(0), m_isBlocked(false) {}


unsigned int Card::GetID()
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
