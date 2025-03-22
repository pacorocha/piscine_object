#ifndef SHOVEL_HPP
#define SHOVEL_HPP
#include <iostream>

class Worker;

struct Shovel
{
  public:
	int numberOfUses;
	Worker *owner;
	Shovel(int uses = 10) : numberOfUses(uses), owner(NULL)
	{
		std::cout << "\e[0;32mShovel created\033[0m" << std::endl;
	}
	~Shovel()
	{
		std::cout << "\e[0;32mShovel destroyed\033[0m" << std::endl;
	}

	void use()
	{
		if (numberOfUses > 0)
		{
			numberOfUses--;
			std::cout << "Shovel used! Remaining uses: " << numberOfUses
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
		return numberOfUses;
	}
	void display() const
	{
		std::cout << "Shovel uses: " << numberOfUses << std::endl;
	}
};

#endif // SHOVEL_HPP