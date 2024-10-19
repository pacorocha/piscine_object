#include "Account.hpp"

Account::Account(void) {}

Account::Account(int id, int initial_amount) :
	_id(id),
	_value(initial_amount) {}

