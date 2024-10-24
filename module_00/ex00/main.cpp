#include "Bank.hpp"
#include "Account.hpp"

int main(void) {
	Bank bank;
	Account* account1 = new Account();
	Account* account2 = new Account();

	account1->setValue(1000);
	bank.addAccount(account1);
	account2->setValue(1000);
	bank.addAccount(account2);

	std::cout << account1->getValue() << std::endl;
	std::cout << account1->getId() << std::endl;
	std::cout << account2->getValue() << std::endl;
	std::cout << account2->getId() << std::endl;

	bank.deposit(account1, 1000);
	std::cout << account1->getValue() << std::endl;
	std::cout << account1->getId() << std::endl;

	bank.deposit(account2, 500);
	std::cout << account2->getValue() << std::endl;
	std::cout << account2->getId() << std::endl;

	std::cout << *account1 << std::endl;
	std::cout << *account2 << std::endl;
	bank.deleteAccount(account1);
	std::cout << "Bank liquidity: " << bank.getLiquidity() << std::endl;
}