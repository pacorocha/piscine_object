#ifndef SHOVEL_HPP
#define SHOVEL_HPP
#include "ATool.hpp"

class Worker;

struct Shovel : public Tool
{

  public:
	Worker *owner;
	Shovel(int uses) : Tool(uses), owner(NULL)
	{
		std::cout << "\e[0;32mShovel created\033[0m" << std::endl;
	}
	~Shovel()
	{
		std::cout << "\e[0;32mShovel destroyed\033[0m" << std::endl;
	}

	void use()
	{
		if (_numberOfUses > 0)
		{
			_numberOfUses--;
			std::cout << "Shovel used! Remaining uses: " << _numberOfUses
					  << std::endl;
		}
		else
		{
			std::cout << "Shovel is worn out!" << std::endl;
		}
	}
	void setOwner(Worker *newOwner)
	{
		owner = newOwner;
	}

	Worker *getOwner() const
	{
		return owner;
	}
	int getUses() const
	{
		return _numberOfUses;
	}
	void display() const
	{
		std::cout << "Shovel uses: " << _numberOfUses << std::endl;
	}
};

#endif