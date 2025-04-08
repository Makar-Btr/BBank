#ifndef CARD_H
#define CARD_H

class Card
{
public:
    Card(size_t id);

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

    // ВАЖНО!
    // Заблокирована возможность использовать конструктор поумолчанию!
    // Банк обязан контролировать ID создаваемых карт, что бы не создать 2 одинаковые.
    Card();
};

#endif // CARD_H
