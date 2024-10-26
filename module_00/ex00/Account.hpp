#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>
#include <iostream>

class Account {
	public:
		int getId() const;
		float getValue() const;
		void setId(int id);
		void setValue(int value);

	private:
		int _id;
		float _value;
		static int ID;

		Account(void);
		Account(int value);
		~Account(void);

		friend class Bank;
	};



std::ostream& operator<<(std::ostream& out, const Account& account);

#endif