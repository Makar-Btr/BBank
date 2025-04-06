#include <QCoreApplication>

class Card;
class Client;
class Bank;

class Card
{
    double balance;
    bool status;

    void Block()
    {
        status = false;
    }
    void Unlock()
    {
        status = true;
    }
    void replenish(double X)
    {
        balance += X;
    }
    void withdraw()
    {

    }
public:

    Card(): balance(0), status(true) {}

    Card(Card& X): balance(X.balance), status(X.status) {}

    Card& operator= (Card& X)
    {
        if (this != &X)
        {
            balance = X.balance;
            status = X.status;
        }
        return *this;
    }

};

class Client
{

};

class Bank
{

};

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);



    return 0;//a.exec();
}
