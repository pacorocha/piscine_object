#include "Bank.hpp"

int Bank::_accountId = 1;

Bank::Account::Account(int id, int value) :
	_id(id),
	_value(value) {}

int Bank::Account::getId() const {
    return _id;
}

int Bank::Account::getValue() const {
    return _value;
}

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

Bank::Account* Bank::createAccount(int value)
{
	int accountId = _accountId++;
	if (accountId >= _accounts.size()) {
		_accounts.resize(accountId + 1, NULL);
	}
	Account* account = new Account(accountId, value);
	_accounts[accountId] = account;
	return account;
}

const Bank::Account& Bank::operator[](int id) const
{
	if (id <= 0 || id >= _accounts.size()) {
		throw std::out_of_range("Account ID out of range");
	}
	return *_accounts[id];
}

void Bank::deleteAccount(int id)
{
	if (id <= 0 || id >= _accounts.size() || _accounts[id] == NULL) {
		throw std::out_of_range("Account ID out of range");
	}
	delete _accounts[id];
	_accounts[id] = NULL;
}

void Bank::deposit(int id, int amount)
{
	if (amount <= 0) {
		throw std::invalid_argument("Deposit amount must be positive");
	}
	float fee = amount * 0.05;
	_liquidity += fee;
	float final_amount = amount - fee;
	Bank::Account& account = const_cast<Account&>(operator[](id));
	account._value += final_amount;
	std::cout << "Made a \e[0;34mdeposit\033[0m of " << final_amount << " to account with ID: " << account._id << std::endl;
}

void Bank::withdraw(int id, int amount)
{
	if (amount <= 0) {
		throw std::invalid_argument("Withdrawal amount must be positive");
	}
	Bank::Account& account = const_cast<Account&>(operator[](id));
	if (account._value < amount) {
		throw std::invalid_argument("Insufficient funds for withdrawal");
	}
	account._value -= amount;
	std::cout << "Made a \e[0;33mwithdrawal\033[0m of " << amount << " from account with ID: " << account._id << std::endl;
}

float Bank::getLiquidity(void) const {
	return this->_liquidity;
}

std::vector<Bank::Account *> Bank::getAccounts(void) const {
	return this->_accounts;
}

void Bank::loan(Account *account, int amount) {
	if (amount > _liquidity) {
		std::cout << "\e[0;31mUnsufficient funds\033[0m to make a loan of " << amount << " to account with ID: " << account->getId() << std::endl;
	}
	else {
		_liquidity -= amount;
		account->setValue(account->getValue() + amount);
		std::cout << "Made a \e[0;33mloan \033[0m of " << amount << " to account with ID: " << account->getId() << std::endl;
	}
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
