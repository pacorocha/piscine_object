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

	private:
		int _liquidity;
		std::vector<Account *> _accounts;
};

#endif