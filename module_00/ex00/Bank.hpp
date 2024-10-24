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

		void addAccount(Account *account);
		void deleteAccount(Account *account);
		void deposit(Account *account, int amount);
		void withdraw(Account *account, int amount);
		float getLiquidity(void);

	private:
		float _liquidity;
		std::vector<Account *> _accounts;
};

#endif