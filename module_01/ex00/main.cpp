#include "Worker.hpp"
#include "Workshop.hpp"

int main(void)
{
	Position pos1(10, 20, 10);
	Position pos2(20, 30, 20);
	Statistic stat1(1, 1);
	Statistic stat2(2, 2);
	std::cout << std::endl;

	std::cout << "**** CREATING TOOLS ****" << std::endl;
	Shovel shovel1(5);
	Hammer hammer1(5);
	shovel1.display();
	std::cout << std::endl;
	std::cout << "**** CREATING WORKERS ****" << std::endl;
	Worker w1("Joe", pos1, stat1);
	Worker w2("John", pos2, stat2);
	std::cout << std::endl;

	std::cout << "**** GIVE TOOLS TO WORKER 1 ****" << std::endl;
	w1.display();
	std::cout << std::endl;
	w1.giveTool(&shovel1);
	w1.giveTool(&shovel1);
	w1.giveTool(&hammer1);
	std::cout << std::endl;
	w1.useTool(&shovel1);
	w1.useTool(&hammer1);
	w1.display();
	std::cout << std::endl;

	std::cout << "**** GIVE TOOLS TO WORKER 2 ****" << std::endl;
	w2.display();
	std::cout << std::endl;

	w2.giveTool(&shovel1);
	w2.giveTool(&hammer1);
	std::cout << std::endl;
	w2.useTool(&shovel1);
	w2.useTool(&hammer1);
	std::cout << std::endl;
	w1.display();
	std::cout << std::endl;
	w2.display();
	std::cout << std::endl;

	std::cout << "**** CREATE WORKSHOPS ****" << std::endl;
	Workshop shop1("Carpentry", "Hammer");
	Workshop shop2("Masonry", "Shovel");
	std::cout << std::endl;

	std::cout << "**** REGISTER WORKERS TO WORKSHOPS ****" << std::endl;
	shop1.registerWorker(&w1);
	shop1.registerWorker(&w2);
	shop2.registerWorker(&w1);
	shop2.registerWorker(&w2);
	std::cout << std::endl;

	std::cout << "**** WORKERS IN WORKSHOPS ****" << std::endl;

	shop1.executeWorkDay();
	shop2.executeWorkDay();

	std::cout << std::endl;

	std::cout << "**** REMOVE TOOLS FROM WORKER ****" << std::endl;
	w2.removeTool(&shovel1);

	return 0;
}