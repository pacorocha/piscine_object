#include "Bank.hpp"

Bank::Bank()
{
	_liquidity = 0;
}

Bank::~Bank()
{
	// _accounts.size();
	// for (size_t i = 0; i < count; i++)
	// {
	// 	/* code */
	// }

}

void Bank::addAccount(Account *account) {
	_accounts.push_back(account);
}

void Bank::deleteAccount(Account *account) {
	int id = account->getId();
	std::cout << "Deleting account with id " << id << std::endl;
	_accounts.erase(_accounts.begin() + id);
}

void Bank::deposit(Account* account, int amount) {
	float fee = amount * 0.05;
	_liquidity += fee;
	account->setValue(account->getValue() + amount - fee);
}

void Bank::withdraw(Account* account, int amount) {
	account->setValue(account->getValue() - amount);
}

float Bank::getLiquidity(void) {
	return this->_liquidity;
}
