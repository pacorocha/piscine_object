#ifndef ATOOL_HPP
#define ATOOL_HPP
#include <iostream>

class Tool
{
  protected:
	int _numberOfUses;

  public:
	Tool(int uses) : _numberOfUses(uses)
	{
		std::cout << "Tool created" << std::endl;
	}
	virtual ~Tool()
	{
		std::cout << "Tool destroyed" << std::endl;
	}
	virtual void use() = 0;
};

#endif // ATOOL_HPP