#include "Account.hpp"

int Account::ID = 0;

Account::Account(void) {
	this->_id = ID++;
}

int Account::getId() const {
	return this->_id;
}

int Account::getValue() const {
	return this->_value;
}

void Account::setValue(int initial_amount) {
	this->_value = initial_amount;
}

Account::~Account(void) {}

std::ostream& operator<<(std::ostream& out, const Account& account) {
	out << "Account " << account.getId() << " has " << account.getValue() << " funds.";
	return out;
};
