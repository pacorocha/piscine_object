#include "Bank.hpp"

int main(void) {
	Bank bank;

	Bank::Account* account1 = bank.createAccount(1000);
	Bank::Account* account2 = bank.createAccount(1000);

	const Bank::Account& acc1 = bank[account1->getId()];
	const Bank::Account& acc2 = bank[account2->getId()];

	std::cout << acc1 << std::endl;
	std::cout << acc2 << std::endl;
	std::cout << std::endl;

	bank.deposit(account1->getId(), 1000);
	std::cout << std::endl;

	try {
		bank.withdraw(account1->getId(), 2000);
	} catch (const std::invalid_argument& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		bank.withdraw(account1->getId(), -200);
	} catch (const std::invalid_argument& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << *account1 << std::endl;
	std::cout << std::endl;

	try {
		bank.deposit(account2->getId(), -500);
	} catch (const std::invalid_argument& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << bank << std::endl;

	bank.loan(account2, 500);
	std::cout << std::endl;

	bank.loan(account1, 25);
	std::cout << std::endl;

	std::cout << bank << std::endl;

	bank.deleteAccount(account1->getId());
	std::cout << std::endl;

	std::cout << bank << std::endl;
}