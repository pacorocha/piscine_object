#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>

class Account {
	public:
		Account(void);
		Account(int id, int value);
		~Account(void);

		int getId() const;
		int getValue() const;
		void setValue(int value);

	private:
		int _id;
		int _value;
	};

#endif