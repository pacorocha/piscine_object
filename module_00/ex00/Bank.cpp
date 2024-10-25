#include "Bank.hpp"

Bank::Bank()
{
	_liquidity = 0;
}

Bank::~Bank()
{
	for (unsigned int i = 0; i < _accounts.size(); i++) {
		delete _accounts[i];
	}
}

Account* Bank::createAccount(int value)
{
	Account* account = new Account(value);
	_accounts.push_back(account);
	return account;
}

void Bank::deleteAccount(Account *account)
{
	std::cout << "\e[0;31mDeleting\033[0m account with ID: " << account->getId() << std::endl;
    for (std::vector<Account*>::iterator it = _accounts.begin(); it != _accounts.end(); ++it) {
        if (*it == account) {
            _accounts.erase(it);
            delete account;
            return;
        }
    }
}

void Bank::deposit(Account* account, int amount)
{
	float fee = amount * 0.05;
	_liquidity += fee;
	float final_amount = amount - fee;
	account->setValue(account->getValue() + final_amount);
	std::cout << "Made a \e[0;34mdeposit\033[0m of " << " to account with ID: " << account->getId() << std::endl;
}

void Bank::withdraw(Account* account, int amount)
{
	account->setValue(account->getValue() - amount);
	std::cout << "Made a \e[0;33mwithdrawal\033[0m of " << amount << " from account with ID: " << account->getId() << std::endl;
}

float Bank::getLiquidity(void) const {
	return this->_liquidity;
}

std::vector<Account *> Bank::getAccounts(void) const {
	return this->_accounts;
}

std::ostream& operator<< (std::ostream& os, const Bank& bank)
{
	os << "\e[0;32mBank informations : \033[0m" << std::endl;
	os << "\e[0;34mLiquidity: \033[0m" << bank.getLiquidity() << std::endl;
	std::vector<Account *> accounts = bank.getAccounts();
	for (unsigned int i = 0; i < accounts.size(); i++) {
		Account *clientAccount = accounts[i];
		os << *clientAccount << std::endl;
	}
	return (os);
}
