#ifndef WORKSHOP_HPP
#define WORKSHOP_HPP

#include "Worker.hpp"
#include <string>
#include <vector>

class Workshop
{
  private:
	std::string _name;
	std::vector<Worker *> _workers;
	std::string _requiredToolType;

  public:
	Workshop(std::string name, std::string requiredTool);
	~Workshop();

	bool workerHasTool(Worker *worker) const;
	void registerWorker(Worker *worker);
	void releaseWorker(Worker *worker);
	void executeWorkDay();
	void display() const;
	std::string getName() const
	{
		return _name;
	}
};

#endif