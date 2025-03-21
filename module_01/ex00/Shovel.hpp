#ifndef SHOVEL_HPP
#define SHOVEL_HPP
#include <iostream>

class Worker;

struct Shovel
{
  public:
	Shovel() : numberOfUses(10), _shovelUser(NULL)
	{
		std::cout << "\e[0;32mShovel created\033[0m" << std::endl;
	}
	~Shovel()
	{
		std::cout << "\e[0;32mShovel destroyed\033[0m" << std::endl;
	}
	void display()
	{
		std::cout << "\e[0;32mShovel uses: " << numberOfUses << "\033[0m"
				  << std::endl;
	}
	void setWorker(Worker *worker)
	{
		_shovelUser = worker;
	}
	Worker *getWorker()
	{
		return _shovelUser;
	}
	int numberOfUses;

  private:
	Worker *_shovelUser;
};

#endif // SHOVEL_HPP