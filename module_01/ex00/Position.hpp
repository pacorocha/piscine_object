#ifndef POSITION_H
#define POSITION_H

#include <iostream>

struct Position
{
	int x;
	int y;
	int z;
	Position(int x, int y, int z) : x(x), y(y), z(z)
	{
		std::cout << "\e[0;34mPosition created (" << x << ", " << y << ", " << z
				  << ")"
				  << "\033[0m" << std::endl;
	}
	~Position()
	{
		std::cout << "\e[0;34mPosition destroyed (" << x << ", " << y << ", "
				  << z << ")"
				  << "\033[0m" << std::endl;
	}
};

#endif // POSITION_H
