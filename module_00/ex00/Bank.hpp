#ifndef BANK_HPP
# define BANK_HPP

# include <iostream>
# include <vector>
# include "Account.hpp"

class Bank
{
	public:
		struct Account {
		private:
			int _id;
			float _value;

			Account(int id, int value);
			~Account(void);

			friend class Bank;

		public:
			int getId(void) const;
			int getValue(void) const;
		};
		Bank(void);
		Bank(Bank const &src);
		~Bank(void);

		Account* createAccount(int value);
		const Account& operator[](int id) const;
		void deleteAccount(int id);
		void deposit(int id, int amount);
		void withdraw(int id, int amount);
		float getLiquidity(void) const;
		void loan(int id, int amount);
		std::vector<Bank::Account *> getAccounts(void) const;

	private:
		float _liquidity;
		std::vector<Bank::Account *> _accounts;
		static int _accountId;
};

std::ostream &operator<<(std::ostream &out, Bank const &bank);

#endif