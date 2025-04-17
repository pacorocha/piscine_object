#include "Worker.hpp"

Worker::Worker(std::string name, Position coords, Statistic stats)
	: _name(name), _coords(coords), _stats(stats)
{
	std::cout << "\e[0;31mWorker " << _name << " created" << std::endl;
}

Worker::~Worker(void)
{
	std::cout << "\e[0;31mWorker " << _name << " destroyed\033[0m" << std::endl;
	for (std::vector<Tool *>::iterator it = _tools.begin(); it != _tools.end();
		 ++it)
	{
		if (Shovel *shovel = dynamic_cast<Shovel *>(*it))
		{
			std::cout << _name << " is deleted, but the shovel remains intact!"
					  << std::endl;
			shovel->setOwner(NULL);
		}
		if (Hammer *hammer = dynamic_cast<Hammer *>(*it))
		{
			std::cout << _name << " is deleted, but the hammer remains intact!"
					  << std::endl;
			hammer->setOwner(NULL);
		}
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

void Worker::giveTool(Tool *tool)
{
	if (tool == NULL)
		return;

	if (std::find(_tools.begin(), _tools.end(), tool) != _tools.end())
	{
		std::cout << _name << " already has this tool!" << std::endl;
		return;
	}

	// Handle transfer of ownership
	if (Shovel *shovel = dynamic_cast<Shovel *>(tool))
	{
		if (Worker *previousOwner = shovel->getOwner())
		{
			previousOwner->removeTool(tool);
		}
		shovel->setOwner(this);
	}
	else if (Hammer *hammer = dynamic_cast<Hammer *>(tool))
	{
		if (Worker *previousOwner = hammer->getOwner())
		{
			previousOwner->removeTool(tool);
		}
		hammer->setOwner(this);
	}

	_tools.push_back(tool);
	std::cout << _name << " received a new tool" << std::endl;
}

void Worker::removeTool(Tool *tool)
{
	std::vector<Tool *>::iterator it =
		std::find(_tools.begin(), _tools.end(), tool);
	if (it != _tools.end())
	{
		// Set tool owner to NULL regardless of type
		if (Shovel *shovel = dynamic_cast<Shovel *>(tool))
			shovel->setOwner(NULL);
		else if (Hammer *hammer = dynamic_cast<Hammer *>(tool))
			hammer->setOwner(NULL);

		// Remove the tool from inventory first
		_tools.erase(it);
		std::cout << _name << " no longer has this tool." << std::endl;

		// Then check workshops and remove worker from those requiring the
		// removed tool
		std::vector<Workshop *> incompatibleWorkshops;
		for (std::vector<Workshop *>::iterator wsIt = _workshops.begin();
			 wsIt != _workshops.end(); ++wsIt)
		{
			if (!(*wsIt)->workerHasTool(this))
			{
				incompatibleWorkshops.push_back(*wsIt);
			}
		}

		// Finally unregister from incompatible workshops
		for (std::vector<Workshop *>::iterator wsIt =
				 incompatibleWorkshops.begin();
			 wsIt != incompatibleWorkshops.end(); ++wsIt)
		{
			(*wsIt)->releaseWorker(this);
		}
	}
}

void Worker::useTool(Tool *tool)
{
	if (std::find(_tools.begin(), _tools.end(), tool) != _tools.end())
	{
		tool->use();
	}
	else
	{
		std::cout << _name << " doesn't have this tool!" << std::endl;
	}
}

void Worker::display(void)
{
	std::cout << "Worker: " << _name << "\n";
	std::cout << "Position: (" << _coords.x << ", " << _coords.y << ")\n";
	std::cout << "Statistic - Level: " << _stats.level
			  << ", Exp: " << _stats.exp << "\n";

	if (_tools.empty())
	{
		std::cout << "No tools\n";
	}
	else
	{
		std::cout << "Tools:\n";
		for (std::vector<Tool *>::iterator it = _tools.begin();
			 it != _tools.end(); ++it)
		{
			if (Shovel *shovel = dynamic_cast<Shovel *>(*it))
				std::cout << "- Shovel - Uses: " << shovel->getUses() << "\n";
			else if (Hammer *hammer = dynamic_cast<Hammer *>(*it))
				std::cout << "- Hammer - Uses: " << hammer->getUses() << "\n";
		}
	}
	std::cout << std::endl;
}

void Worker::registerToWorkshop(Workshop *workshop)
{
	if (workshop && !isRegisteredAt(workshop))
	{
		_workshops.push_back(workshop);
	}
}

void Worker::unregisterFromWorkshop(Workshop *workshop)
{
	std::vector<Workshop *>::iterator it =
		std::find(_workshops.begin(), _workshops.end(), workshop);
	if (it != _workshops.end())
	{
		_workshops.erase(it);
	}
}

bool Worker::isRegisteredAt(Workshop *workshop) const
{
	return std::find(_workshops.begin(), _workshops.end(), workshop) !=
		   _workshops.end();
}

void Worker::work(Workshop *workshop)
{
	if (!isRegisteredAt(workshop))
	{
		std::cout << _name << " is not registered at " << workshop->getName()
				  << std::endl;
		return;
	}

	// Check if worker still has the required tool
	if (!workshop->workerHasTool(this))
	{
		std::cout << _name << " can't work at " << workshop->getName()
				  << " without the required tool!" << std::endl;
		workshop->releaseWorker(this);
		return;
	}

	std::cout << _name << " is working at " << workshop->getName() << std::endl;
	for (std::vector<Tool *>::iterator it = _tools.begin(); it != _tools.end();
		 ++it)
	{
		(*it)->use();
	}
}
