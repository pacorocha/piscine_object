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
	if (_shovel)
	{
		std::cout << _name << " is deleted, but the shovel remains intact!"
				  << std::endl;
		_shovel->setOwner(NULL);
	}
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

void Worker::giveShovel(Shovel *newShovel)
{
	if (_shovel == newShovel)
	{
		std::cout << _name << " already has this shovel!" << std::endl;
		return;
	}

	if (newShovel)
	{
		Worker *previousOwner = newShovel->getOwner();
		if (previousOwner)
		{
			previousOwner->removeShovel();
			std::cout << "Shovel transferred from " << previousOwner->_name
					  << " to " << _name << std::endl;
		}
	}

	// Assign the shovel
	_shovel = newShovel;
	if (_shovel)
	{
		_shovel->setOwner(this);
	}
}

void Worker::removeShovel()
{
	if (_shovel)
	{
		std::cout << _name << " no longer has a shovel." << std::endl;
		_shovel->setOwner(NULL);
		_shovel = NULL;
	}
}

void Worker::useShovel()
{
	if (_shovel)
	{
		_shovel->use();
	}
	else
	{
		std::cout << _name << " has no shovel to use!" << std::endl;
	}
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