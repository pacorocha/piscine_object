#include "Worker.hpp"

Worker::Worker(std::string name, Position coords, Statistic stats)
	: _name(name), _coords(coords), _stats(stats), _shovel(NULL)
{
	std::cout << "\e[0;31mWorker " << _name << " created\033[0m" << std::endl;
	std::cout << "Worker " << _name << " position: " << _coords.x << ", "
			  << _coords.y << std::endl;
	std::cout << "Worker " << _name << " stats: " << _stats.level << ", "
			  << _stats.exp << std::endl;
}

Worker::~Worker(void)
{
	std::cout << "\e[0;31mWorker " << _name << " destroyed\033[0m" << std::endl;
}

std::string Worker::getName()
{
	return _name;
}
Position Worker::getPosition()
{
	return _coords;
}
Statistic Worker::getStatistic()
{
	return _stats;
}
void Worker::setPosition(Position coords)
{
	_coords = coords;
}
void Worker::setStatistic(Statistic stats)
{
	_stats = stats;
}

void Worker::giveShovel(Shovel *shovel)
{
	if (shovel->getWorker() != NULL)
	{
		// Remove shovel from current owner
		Worker *currentOwner = shovel->getWorker();
		currentOwner->_shovel = NULL;
	}

	_shovel = shovel;
	shovel->setWorker(this);
	std::cout << "Worker " << _name << " received a shovel" << std::endl;
}

Shovel *Worker::takeShovel()
{
	if (_shovel == NULL)
		return NULL;

	Shovel *temp = _shovel;
	_shovel->setWorker(NULL);
	_shovel = NULL;
	std::cout << "Worker " << _name << " lost the shovel" << std::endl;
	return temp;
}
bool Worker::hasShovel()
{
	std::cout << "Worker " << _name << " has a shovel" << std::endl;
	return _shovel != NULL;
}
void Worker::display(void)
{
	std::cout << "Worker: " << _name << "\n";
	std::cout << "Position: (" << _coords.x << ", " << _coords.y << ")\n";
	std::cout << "Statistic - Level: " << _stats.level
			  << ", Exp: " << _stats.exp << "\n";
	if (_shovel)
		std::cout << "Shovel - Uses: " << _shovel->numberOfUses << "\n";
	else
		std::cout << "No shovel\n";
	std::cout << std::endl;
}