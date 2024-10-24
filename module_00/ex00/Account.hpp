#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>
#include <iostream>

class Account {
	protected:
		static int ID;

	public:
		Account(void);
		Account(int value);
		~Account(void);

		int getId() const;
		int getValue() const;
		void setId(int id);
		void setValue(int value);

	private:
		int _id;
		int _value;
	};



std::ostream& operator<<(std::ostream& out, const Account& account);

#endif