#include "Account.hpp"

int Account::ID = 0;

Account::Account(void) {
	this->_id = ID++;
}

Account::Account(int value) {
	this->_id = ID++;
	this->_value = value;
}

int Account::getId() const {
	return this->_id;
}

float Account::getValue() const {
	return this->_value;
}

void Account::setValue(int initial_amount) {
	this->_value = initial_amount;
}

Account::~Account(void) {}

std::ostream& operator<<(std::ostream& out, const Account& account) {
	out << "\e[0;33mAccount [" << account.getId() << "]\033[0m has " << account.getValue() << " funds.";
	return out;
};
