#include "Bank.hpp"
#include "Account.hpp"

int main(void) {
	Bank bank;

	// Account* account4 = new Account();
	Account* account1 = bank.createAccount(1000);
	Account* account2 = bank.createAccount(1000);

	std::cout << *account1 << std::endl;
	std::cout << *account2 << std::endl;
	// std::cout << *account4 << std::endl;
	std::cout << std::endl;

	bank.deposit(account1, 1000);
	std::cout << std::endl;

	bank.withdraw(account1, 2000);
	std::cout << std::endl;

	bank.withdraw(account1, 200);
	std::cout << std::endl;

	bank.deposit(account2, 500);
	std::cout << std::endl;

	std::cout << bank << std::endl;

	bank.loan(account2, 500);
	std::cout << std::endl;

	bank.loan(account1, 25);
	std::cout << std::endl;

	std::cout << bank << std::endl;

	bank.deleteAccount(account1);
	std::cout << std::endl;

	Account* account3 = bank.createAccount(1000);
	bank.withdraw(account3, 200);
	std::cout << std::endl;

	std::cout << bank << std::endl;
}