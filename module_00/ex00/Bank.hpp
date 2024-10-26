#ifndef BANK_HPP
# define BANK_HPP

# include <iostream>
# include <vector>
# include "Account.hpp"

class Bank
{
	public:
		Bank(void);
		Bank(Bank const &src);
		~Bank(void);

		Account* createAccount(int value);
		void deleteAccount(Account *account);
		void deposit(Account *account, int amount);
		void withdraw(Account *account, int amount);
		float getLiquidity(void) const;
		void loan(Account *account, int amount);
		std::vector<Account *> getAccounts(void) const;

	private:
		float _liquidity;
		std::vector<Account *> _accounts;
};

std::ostream &operator<<(std::ostream &out, Bank const &bank);

#endif