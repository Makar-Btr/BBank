#ifndef CARD_H
#define CARD_H

class Card
{
public:
    Card(unsigned int id);

    unsigned int GetID();

    bool IsBlocked();
    void Block();
    void UnBlock();

    double GetBalance();
    // value - значение которое будет прибавлено к балансу.
    // Если положительное - баланс будет увеличен.
    // Если отрицательное - баланс будет уменьшен.
    void UpdateBalance(const double& value);

private:
    unsigned int m_id;
    double m_balance;
    bool m_isBlocked;

    // ВАЖНО!
    // Заблокирована возможность использовать конструктор поумолчанию!
    // Банк обязан контролировать ID создаваемых карт, что бы не создать 2 одинаковые.
    Card();
};

#endif // CARD_H
