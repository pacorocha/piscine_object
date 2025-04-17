#include "Workshop.hpp"

Workshop::Workshop(std::string name, std::string requiredTool)
	: _name(name), _requiredToolType(requiredTool)
{
	std::cout << "\e[0;45mWorkshop " << _name << " created\033[0m" << std::endl;
}

Workshop::~Workshop()
{
	std::cout << "\e[0;45mWorkshop " << _name << " destroyed\033[0m"
			  << std::endl;
}

bool Workshop::Workshop::workerHasTool(Worker *worker) const
{
	if (_requiredToolType == "Shovel")
	{
		if (worker->getTool<Shovel>() != NULL)
			return true;
	}
	else if (_requiredToolType == "Hammer")
	{
		if (worker->getTool<Hammer>() != NULL)
			return true;
	}
	else
	{
		std::cout << "Unknown tool type: " << _requiredToolType << std::endl;
		return false;
	}
	return false;
}

void Workshop::registerWorker(Worker *worker)
{
	if (worker == NULL)
		return;

	if (!workerHasTool(worker))
	{
		std::cout << worker->getName()
				  << " does not have the required tool: " << _requiredToolType
				  << std::endl;
		return;
	}
	if (std::find(_workers.begin(), _workers.end(), worker) != _workers.end())
	{
		std::cout << worker->getName() << " is already registered at " << _name
				  << std::endl;
		return;
	}

	_workers.push_back(worker);
	worker->registerToWorkshop(this);
	std::cout << "\e[0;35m" << worker->getName() << " registered at " << _name
			  << "\033[0m" << std::endl;
}

void Workshop::releaseWorker(Worker *worker)
{
	std::vector<Worker *>::iterator it =
		std::find(_workers.begin(), _workers.end(), worker);
	if (it != _workers.end())
	{
		_workers.erase(it);
		worker->unregisterFromWorkshop(this);
		std::cout << "\e[0;35m" << worker->getName()
				  << " has been released from " << _name << "\033[0m"
				  << std::endl;
	}
}

void Workshop::executeWorkDay()
{
	std::cout << "\n=== " << _name << " work day begins ===" << std::endl;
	for (std::vector<Worker *>::iterator it = _workers.begin();
		 it != _workers.end(); ++it)
	{
		(*it)->work(this);
	}
	std::cout << "=== " << _name << " work day ends ===\n" << std::endl;
}

void Workshop::display() const
{
	std::cout << "Workshop: " << _name << std::endl;
	if (_workers.empty())
	{
		std::cout << "No workers registered\n" << std::endl;
		return;
	}

	std::cout << "Registered workers:" << std::endl;
	for (std::vector<Worker *>::const_iterator it = _workers.begin();
		 it != _workers.end(); ++it)
	{
		std::cout << "- " << (*it)->getName() << std::endl;
	}
	std::cout << std::endl;
}
