#include "Worker.hpp"

int main(void)
{
	Position pos1(10, 20, 10);
	Statistic stat1(1, 1);
	std::cout << std::endl;

	Shovel shovel1(5);
	Worker w1("Worker1", pos1, stat1);
	Worker w2("Worker2", pos1, stat1);
	std::cout << std::endl;

	shovel1.display();

	w1.giveShovel(&shovel1);
	w1.useShovel();
	w1.display();
	w2.display();
	std::cout << std::endl;

	w2.giveShovel(&shovel1);
	w2.useShovel();
	w1.display();
	w2.display();
	std::cout << std::endl;

	return 0;
}