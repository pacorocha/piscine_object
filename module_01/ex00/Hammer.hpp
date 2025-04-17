#ifndef HAMMER_HPP
#define HAMMER_HPP
#include "ATool.hpp"

class Worker;

struct Hammer : public Tool
{

  private:
	Worker *_owner;

  public:
	Hammer(int uses) : Tool(uses), _owner(NULL)
	{
		std::cout << "\e[0;32mHammer created\033[0m" << std::endl;
	}
	~Hammer()
	{
		std::cout << "\e[0;32mHammer destroyed\033[0m" << std::endl;
	}

	void use()
	{
		if (_numberOfUses > 0)
		{
			_numberOfUses--;
			std::cout << "Hammer used! Remaining uses: " << _numberOfUses
					  << std::endl;
		}
		else
		{
			std::cout << "Hammer is worn out!" << std::endl;
		}
	}
	void setOwner(Worker *newOwner)
	{
		_owner = newOwner;
	}

	Worker *getOwner() const
	{
		return _owner;
	}
	int getUses() const
	{
		return _numberOfUses;
	}
	void display() const
	{
		std::cout << "Hammer uses: " << _numberOfUses << std::endl;
	}
};

#endif