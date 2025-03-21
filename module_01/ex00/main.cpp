#include "Worker.hpp"

int main(void)
{
	Position pos1(10, 20, 10);
	Statistic stat1(1, 1);

	Worker worker1("Worker1", pos1, stat1);
	Worker worker2("Worker2", pos1, stat1);

	Shovel shovel1;

	std::cout << "\nGiving shovel to Worker1..." << std::endl;
	worker1.giveShovel(&shovel1);
	worker1.display();
	worker2.display();

	std::cout << "\nGiving shovel to Worker2..." << std::endl;
	worker2.giveShovel(&shovel1);
	worker1.display();
	worker2.display();

	std::cout << "\nTaking shovel from worker..." << std::endl;
	Shovel *returned_shovel = worker2.takeShovel();
	worker1.display();
	worker2.display();

	std::cout << "\nWorker will be destroyed, but shovel remains..."
			  << std::endl;

	if (returned_shovel == &shovel1)
	{
		std::cout << "Shovel is still the same object!" << std::endl;
	}

	return 0;
}