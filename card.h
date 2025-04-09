#ifndef CARD_H
#define CARD_H

#include <cstddef>

class Card
{
public:
    // Не использовать!!!
    // Нужен только для мап!
    Card(){}

    Card(size_t id);
    Card(const Card& O);
    Card& operator= (const Card& O);

    size_t GetID();

    bool IsBlocked();
    void Block();
    void UnBlock();

    double GetBalance();
    // value - значение которое будет прибавлено к балансу.
    // Если положительное - баланс будет увеличен.
    // Если отрицательное - баланс будет уменьшен.
    void UpdateBalance(const double& value);

private:
    size_t m_id;
    double m_balance;
    bool m_isBlocked;
};

#endif // CARD_H
