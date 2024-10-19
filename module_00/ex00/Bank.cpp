#include "Bank.hpp"

Bank::Bank()
{
    this->_accounts = new std::vector<Account*>();
}

Bank::~Bank()
{
    for (int i = 0; i < this->accounts->size(); i++)
    {
        delete this->accounts->at(i);
    }
    delete this->accounts;
}
