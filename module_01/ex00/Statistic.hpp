#ifndef STATISTIC_H
#define STATISTIC_H
#include <iostream>

#endif // STATISTIC_H

struct Statistic
{
	int level;
	int exp;
	Statistic(int l, int e) : level(l), exp(e)
	{
		std::cout << "\e[0;33mStatistic created: level = " << level
				  << ", exp = " << exp << "\033[0m" << std::endl;
	}
	~Statistic()
	{
		std::cout << "\e[0;33mStatistic destroyed: level = " << level
				  << ", exp = " << exp << "\033[0m" << std::endl;
	}
};
